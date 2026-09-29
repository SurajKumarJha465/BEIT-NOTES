//Structure Demo

#include <stdio.h>
#include <stdlib.h>

struct Name{
    char *firstName;
    char *lastName;
};

struct Student{
    struct Name name;
    int age;
};

int main(){
    struct Student *stu;
    stu = (struct Student*) malloc(sizeof(struct Student));

    stu->name.firstName = "Ram";
    stu->name.lastName  = "Khadka";
    stu->age = 24;

    printf("%d",sizeof(struct Student));
    return 0;
}
