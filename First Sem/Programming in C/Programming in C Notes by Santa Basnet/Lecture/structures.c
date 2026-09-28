#include<stdio.h>
#include<string.h>
/**
 * Structure initialization.
 */
struct Person {
    char name[100];
    int age;
    float weight;
};

struct Point {
    int x, y;
};

/** Nested Structure **/
struct Rectangle {
    struct Point pt1, pt2;
};

/**
 * Main function, program starts here.
 * @return 0 with successful completion.
 */

int main() {
    struct Person shyam = {"Shyam Karki", 22, 56.9f};

    struct Person ram;
    strcpy(ram.name, "Ram Thakur");
    ram.age = 34;
    ram.weight = 55.02f;

    struct Person persons[2] = {
            {"Shyam, Karki", 22, 56.9f},
            {"Ram Thakur", 34, 55.02f}
    };

    struct Person persons1[2] = {ram, shyam}; // Array of Structures.

    printf("{Name: %s, age: %d and weight: %.2f}\n", shyam.name, shyam.age, shyam.weight);

    struct Rectangle rect = {
            {0, 0},
            {4, 3}
    };
    return 0;
}


