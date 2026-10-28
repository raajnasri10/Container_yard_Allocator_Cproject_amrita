#include <stdio.h>
#include "container.h"

//Input the datails of containers
void registerContainer(struct Container containers[], int *count){

    if(*count >= 10){
        printf("\nYard is full! Cannot register more containers.\n");
        return;
    }

    printf("\n--- REGISTER CONTAINER ---\n");

    printf("Enter Container ID: ");
    scanf("%s", containers[*count].id);

    printf("Enter Container Type: ");
    scanf("%s", containers[*count].type);

    printf("Enter Container Size: ");
    scanf("%d", &containers[*count].size);

    printf("Enter Arrival Date: ");
    scanf("%s", containers[*count].arrival);

    printf("Enter Departure Date: ");
    scanf("%s", containers[*count].departure);

    printf("Enter Priority (1-5): ");
    scanf("%d", &containers[*count].priority);

    printf("Hazardous? (1 = Yes, 0 = No): ");
    scanf("%d", &containers[*count].hazardous);

    containers[*count].slot = -1;

    (*count)++;

    printf("\nContainer registered successfully!\n");
}

//displaying all the containers registered
void displayContainer(struct Container containers[], int count){

    printf("\n--- EXISTING CONTAINERS ---\n");

    if(count == 0){
        printf("No containers registered.\n");
        return;
    }

    for(int i = 0; i < count; i++){

        printf("\nContainer %d\n", i + 1);
        printf("Container ID: %s\n", containers[i].id);
        printf("Container Type: %s\n", containers[i].type);
        printf("Container Size: %d\n", containers[i].size);
        printf("Arrival: %s\n", containers[i].arrival);
        printf("Departure: %s\n", containers[i].departure);
        printf("Priority: %d\n", containers[i].priority);
        printf("Hazardous: %s\n",
               containers[i].hazardous ? "YES" : "NO");
        printf("Allocated Slot: %d\n", containers[i].slot);

        printf("\n");
    }
}

//Sorting containers by the priority as a order of highest to lowest
void sortContainers_priority(struct Container containers[], int count){
    int i, j;
    struct Container temp;

    for(i = 0; i < count - 1; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(containers[i].priority < containers[j].priority)
            {
                temp = containers[i];
                containers[i] = containers[j];
                containers[j] = temp;
            }
        }
    }
}


