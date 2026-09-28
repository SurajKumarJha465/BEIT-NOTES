/** Self referential pointer **/
#include<stdlib.h>
#include<stdio.h>

struct Customer {
    int id;
    struct Customer *next;
};

enum Boolean {
    FALSE, TRUE
};

struct Customer *createCustomer(int data) {
    struct Customer *customer;
    customer = (struct Customer *) malloc(sizeof(struct Customer));
    customer->id = data;
    customer->next = NULL;
    return customer;
}

void displayCustomers(struct Customer *start) {
    printf("\nAvailable Customers: \n");
    printf("--------------------------------------------\n");
    while (start != NULL) {
        printf("[%X|%d|%X] --> ", start, start->id, start->next);
        start = start->next;
    }
    printf("\n--------------------------------------------\n");
}
/** Appending a new customer at last position.**/
struct Customer *appendCustomer(struct Customer *start, int data) {
    if (start == NULL) start = createCustomer(data);
    else {
        struct Customer *tmp = start;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = createCustomer(data);
    }
    return start;
}

enum Boolean findById(int id, struct Customer *start) {
    while (start != NULL) {
        if (start->id == id) return TRUE;
        start = start->next;
    }
    return FALSE;
}
/** Cleaning up the allocated memory **/
void cleanUp(struct Customer *start){
    while(start != NULL){
        struct Customer *tmp = start;
        start = start -> next;
        free(tmp);
    }
    printf("\nMemory cleaned-up successfully !\n");
}

int main() {
    struct Customer *start = NULL;
    start = appendCustomer(start, 1);
    start = appendCustomer(start, 2);
    start = appendCustomer(start, 3);
    start = appendCustomer(start, 4);
    displayCustomers(start);
    cleanUp(start);

    /**
    struct Customer *soon = createCustomer(1);
    struct Customer *hira = createCustomer(2);
    soon->next = hira;

    struct Customer *moti = createCustomer(3);
    hira->next = moti;

    struct Customer *chaandi = createCustomer(4);
    moti->next = chaandi;

    int tId = 4;
    enum Boolean found = findById(tId, soon);
    if (found) printf("\nFound ! %d\n", tId);
    else printf("\nNot Found ! %d\n", tId);

    tId = 3;
    found = findById(tId, soon);
    if (found) printf("\nFound ! %d\n", tId);
    else printf("\nNot Found ! %d\n", tId);

    displayCustomers(soon);
    free(soon);
    free(moti);
    free(hira);
    free(chaandi);
     **/
    return 0;
}