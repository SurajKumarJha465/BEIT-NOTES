//Self reference structure

#include <stdio.h>
#include <stdlib.h>

struct Point{
    int x, y;
    struct Point *next;
};

struct Point *start = NULL;
struct Point *current = NULL;

int main(){
    struct Point *tmp;
    char ch = 'y';
    while(ch == 'y')
    {
        tmp = malloc(sizeof(struct Point));
        printf("Enter a coordinate(x, y) : ");
        scanf("%d %d", &tmp->x, &tmp->y);
        tmp->next = NULL;
        if(start == NULL){
            start = current = tmp;
        }else{
            current->next = tmp;
            current = tmp;
        }
        printf("Do you want another(y/n) : ");
        scanf(" %c",&ch);
    }

    //Printing all Values
    printf("Iterating all Values : \n");
    while(start){
        printf("(%d, %d)\n", start->x, start->y);
        start = start->next;
    }
    return 0;
}
