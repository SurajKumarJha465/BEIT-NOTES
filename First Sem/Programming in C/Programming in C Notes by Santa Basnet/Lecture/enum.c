
#include<stdio.h>

enum Boolean {
    NO, YES
};

enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

enum HairColor {BLACK, WHITE, BROWN, RED};

int main() {
    enum Boolean value = YES;
    printf("YES: %d\n", value);

    enum Month month = DEC;
    printf("Month: %d\n", month);
    return 0;
}