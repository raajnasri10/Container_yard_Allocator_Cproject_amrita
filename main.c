#include <stdio.h>
#include <string.h>
#include "container.h"
#include "allocator.h"


int main(){
    int choice;
    struct Container containers[10];
    int count = 0;
    
    struct Slot slots[16];
    initializeSlots(slots);
   do{
    
    printf("\n--- CONTAINER YARD SLOT ALLOCATOR ---\n");
    printf("1. Register New Container\n");
    printf("2. View Existing Containers\n");
    printf("3. View Yard\n");
    printf("4. Sort Containers (Priority)\n");
    printf("5. Allocate Container to Slot\n");
    printf("6. View Yard Summary\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            registerContainer(containers, &count);
            break;
        case 2:
            displayContainer(containers, count); 
            break;
        case 3:
            displaySlots(slots);
            break;
        
        case 4:
            sortContainers_priority(containers, count);

            printf("\n--- CONTAINERS SORTED BY PRIORITY ---\n");

            for (int i = 0; i < count; i++)
            {
                if (containers[i].slot >= 0 && containers[i].slot < 16)
                {
                    printf("%d. %s - Priority %d - Departure: %s - Slot: %s\n",
                        i + 1,
                        containers[i].id,
                        containers[i].priority,
                        containers[i].departure,
                        slots[containers[i].slot].slotID);
                }
                else
                {
                    printf("%d. %s - Priority %d - Departure: %s - Slot: Not Allocated\n",
                        i + 1,
                        containers[i].id,
                        containers[i].priority,
                        containers[i].departure);
                }
            }
            break;

        case 5:
            char containerID[10];
            int found = 0;

            printf("Enter Container ID to allocate: ");
            scanf("%9s", containerID);
            //To allocate the container to a slot
            for (int i = 0; i < count; i++) {
                if (strcmp(containers[i].id, containerID) == 0) {
                    found = 1;

                    if (containers[i].slot != -1) {
                        int slotIndex = containers[i].slot;

                        printf("Error: Container %s is already allocated to slot %s.\n",
                            containers[i].id, slots[slotIndex].slotID);
                    } else {
                        int slotIndex = allocateContainer(slots, containers[i]);

                        if (slotIndex >= 0) {
                            containers[i].slot = slotIndex;

                            printf("Container %s allocated to slot %s.\n",
                                containers[i].id, slots[slotIndex].slotID);
                        } else if (slotIndex == -2) {
                            printf("Error: Container is already allocated.\n");
                        } else {
                            printf("No compatible slot available.\n");
                        }
                    }

                    break;
                }
            }
            if (!found) {
                printf("Error: Container ID %s not found.\n", containerID);
            }
            break;

        case 6:
            displayYardSummary(slots);
            break;

        case 7:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");

    }
   }while(choice !=7);

   return 0;
}