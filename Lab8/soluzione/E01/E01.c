int atomicIncrement (int *var) {
    int tmp = *var;
    *var = tmp + 1;
    return (tmp);
}

typedef struct{
    int ticketNumber;
    int turnNumber;
}var;

void init(var a){
    a.ticketNumber=0;
    a.turnNumber=0;
}

void lock(var a){
    int turnoeff = atomicIncrement(&a.ticketNumber);
    while(a.turnNumber != turnoeff);
}

void unlock(var a){
    atomicIncrement(&a.turnNumber);
}