#include <stdio.h>
#include <string.h>
#include "allocator.h"

//Initializing 16 slots 
void initializeSlots(struct Slot slots[]){
//TYPE - General; SIZE - 20
    strcpy(slots[0].slotID, "A1");
    slots[0].size = 20;
    strcpy(slots[0].type, "General");
    slots[0].hazardous = 0;
    slots[0].occupied = 0;
    strcpy(slots[0].containerID, "");

    strcpy(slots[1].slotID, "A2");
    slots[1].size = 20;
    strcpy(slots[1].type, "General");
    slots[1].hazardous = 0;
    slots[1].occupied = 0;
    strcpy(slots[1].containerID, "");

    strcpy(slots[2].slotID, "A3");
    slots[2].size = 20;
    strcpy(slots[2].type, "General");
    slots[2].hazardous = 1;
    slots[2].occupied = 0;
    strcpy(slots[2].containerID, "");

    strcpy(slots[3].slotID, "A4");
    slots[3].size = 20;
    strcpy(slots[3].type, "General");
    slots[3].hazardous = 1;
    slots[3].occupied = 0;
    strcpy(slots[3].containerID, "");
//TYPE - General; Size - 40
    strcpy(slots[4].slotID, "B1");
    slots[4].size = 40;
    strcpy(slots[4].type, "General");
    slots[4].hazardous = 0;
    slots[4].occupied = 0;
    strcpy(slots[4].containerID, "");

    strcpy(slots[5].slotID, "B2");
    slots[5].size = 40;
    strcpy(slots[5].type, "General");
    slots[5].hazardous = 0;
    slots[5].occupied = 0;
    strcpy(slots[5].containerID, "");

    strcpy(slots[6].slotID, "B3");
    slots[6].size = 40;
    strcpy(slots[6].type, "General");
    slots[6].hazardous = 1;
    slots[6].occupied = 0;
    strcpy(slots[6].containerID, "");

    strcpy(slots[7].slotID, "B4");
    slots[7].size = 40;
    strcpy(slots[7].type, "General");
    slots[7].hazardous = 1;
    slots[7].occupied = 0;
    strcpy(slots[7].containerID, "");
//TYPE - Reefer; Size - 20
    strcpy(slots[8].slotID, "C1");
    slots[8].size = 20;
    strcpy(slots[8].type, "Reefer");
    slots[8].hazardous = 0;
    slots[8].occupied = 0;
    strcpy(slots[8].containerID, "");

    strcpy(slots[9].slotID, "C2");
    slots[9].size = 20;
    strcpy(slots[9].type, "Reefer");
    slots[9].hazardous = 1;
    slots[9].occupied = 0;
    strcpy(slots[9].containerID, "");
//TYPE - Reefer; Size - 40
    strcpy(slots[10].slotID, "C3");
    slots[10].size = 40;
    strcpy(slots[10].type, "Reefer");
    slots[10].hazardous = 0;
    slots[10].occupied = 0;
    strcpy(slots[10].containerID, "");

    strcpy(slots[11].slotID, "C4");
    slots[11].size = 40;
    strcpy(slots[11].type, "Reefer");
    slots[11].hazardous = 1;
    slots[11].occupied = 0;
    strcpy(slots[11].containerID, "");
//TYPE - OpenTop ; Size - 20
    strcpy(slots[12].slotID, "D1");
    slots[12].size = 20;
    strcpy(slots[12].type, "OpenTop");
    slots[12].hazardous = 0;
    slots[12].occupied = 0;
    strcpy(slots[12].containerID, "");

    strcpy(slots[13].slotID, "D2");
    slots[13].size = 20;
    strcpy(slots[13].type, "OpenTop");
    slots[13].hazardous = 1;
    slots[13].occupied = 0;
    strcpy(slots[13].containerID, "");
//TYPE - OpenTop; Size - 40
    strcpy(slots[14].slotID, "D3");
    slots[14].size = 40;
    strcpy(slots[14].type, "OpenTop");
    slots[14].hazardous = 0;
    slots[14].occupied = 0;
    strcpy(slots[14].containerID, "");

    strcpy(slots[15].slotID, "D4");
    slots[15].size = 40;
    strcpy(slots[15].type, "OpenTop");
    slots[15].hazardous = 1;
    slots[15].occupied = 0;
    strcpy(slots[15].containerID, "");
}

//Allocating container based on type, size and hazardous status
int allocateContainer(struct Slot slots[], struct Container container) {
    for(int i = 0; i < 16; i++){
        if(slots[i].occupied == 1 && strcmp(slots[i].containerID, container.id) == 0){
            printf("ERROR: Container %s is aloready allocated to the slot %s.\n", container.id, slots[i].slotID);
            return -2;
        }
    }
    for (int i = 0; i < 16; i++) {
        if (slots[i].occupied == 0) {
            if (slots[i].size == container.size) {
                if (strcmp(slots[i].type, container.type) == 0) {
                    if (slots[i].hazardous == container.hazardous) {
                        slots[i].occupied = 1;
                        strcpy(slots[i].containerID, container.id);
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}

//Viewing all the slots
void displaySlots(struct Slot slots[]) {
    printf("\n--- YARD SLOT STATUS ---\n");

    for (int i = 0; i < 16; i++) {
        printf("\nSlot ID: %s", slots[i].slotID);
        printf("\nSize: %d", slots[i].size);
        printf("\nType: %s", slots[i].type);
        printf("\nHazardous: %s",
               slots[i].hazardous ? "Yes" : "No");
        printf("\nStatus: %s",
               slots[i].occupied ? "Occupied" : "Available");

        if (slots[i].occupied) {
            printf("\nContainer ID: %s", slots[i].containerID);
        }

        printf("\n----------------------\n");
    }
}

//Displaying summary of the yard with percentage of yard occupied
void displayYardSummary(struct Slot slots[]){
    int totalSlots = 16;
    int occupiedSlots = 0;

    for(int i = 0; i < totalSlots; i++){
        if(slots[i].occupied == 1){
            occupiedSlots++;
        }
    }

    int availableSlots = totalSlots - occupiedSlots;
    float utilization = (float)occupiedSlots / totalSlots * 100;

    printf("\n======YARD SUMMARY========\n");
    printf("Total Slots  : %d\n", totalSlots);
    printf("Occupied Slots   : %d\n", occupiedSlots);
    printf("Available slots   : %d\n", availableSlots);
    printf("Yard Utilization : %.2f%%\n", utilization);
    printf("========================================\n");
}