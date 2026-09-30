#include "container.h"

struct Slot{
    char slotID[5];
    int size;
    char type[20];
    int hazardous;
    int occupied;
    char containerID[20];
};

void initializeSlots(struct Slot slots[]);

int allocateContainer(struct Slot Slots[], struct Container containers);