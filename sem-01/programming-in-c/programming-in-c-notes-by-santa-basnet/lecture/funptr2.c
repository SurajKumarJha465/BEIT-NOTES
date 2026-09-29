#include <stdio.h>

// Sum a + b
void Sum(char* name, int a, int b)
{
    printf("%s gives: %d\n", name, (a+b));
}

// Calling from main
int main()
{
    // Some funky function pointer assignment
    void (*s1Ptr)(char*, int, int) = Sum;
    void (*s2Ptr)(char*, int, int) = *Sum;
    void (*s3Ptr)(char*, int, int) = &Sum;
    void (*s4Ptr)(char*, int, int) = **Sum;
    void (*s5Ptr)(char*, int, int) = ***Sum;

    // Execution still works
    (*s1Ptr)("s1Ptr", 10, 2);
    (*s2Ptr)("s2Ptr", 10, 2);
    (*s3Ptr)("s3Ptr", 10, 2);
    (*s4Ptr)("s4Ptr", 10, 2);
    (*s5Ptr)("s5Ptr", 10, 2);

    return(1);
}
