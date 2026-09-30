#include <stdio.h>
#include "container.h"
#include "allocator.h"


int main(){
    int choice;
    struct Container containers[10];
    int count = 0;
    
    struct Slot slots[16];
    initializeSlots(slots);
   do{
    printf("\n---CONTAINER YARD SLOT ALLOCATOR---\n");
    printf("1. Register New Container\n");
    printf("2. View Existing Containers\n");
    printf("3. View Yard\n");
    printf("4.Sort container(priority\n)");
    printf("5. Exit\n");

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
            printf("View yard selected");
            break;
        case 4:
            sortContainers_priority(containers, count);

            printf("\n--- CONTAINERS SORTED BY PRIORITY ---\n");

            for (int i = 0; i < count; i++)
            {
                printf("%d. %s - Priority %d\n",
                    i + 1,
                    containers[i].id,
                    containers[i].priority);
            }
            break;
        case 5:
            printf("Exiting..\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");

    }
   }while(choice !=5);

   return 0;
}