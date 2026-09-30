struct Container{
    char id[20];
    char type[20];
    int size;
    char arrival[11];
    char departure[11];
    int priority;
    int hazardous;
    int slot;
};

void registerContainer(struct Container containers[], int *count);
void displayContainer(struct Container containers[], int count);
void sortContainers_priority(struct Container containers[], int count);

