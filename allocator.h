#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "container.h"

struct Slot {
    char slotID[5];
    int size;
    char type[20];
    int hazardous;
    int occupied;
    char containerID[20];
};

void initializeSlots(struct Slot slots[]);
int allocateContainer(struct Slot slots[], struct Container container);
void displaySlots(struct Slot slots[]);
void displayYardSummary(struct Slot slots[]);

#endif
