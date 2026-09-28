/** Returning character pointer **/
#include<string.h>
#include<stdlib.h>
#include <stdio.h>

char UCaseChar(char);
char *UCase(char *);

/** Main Function, return 0 for successful outcome **/
int main() {
    static char *givenName = "hira bahadur";
    char *result = UCase(givenName);
    printf("Original: \"%s\" --> Uppercase: \"%s\"", givenName, result);
    free(result);
    return 0;
}

/** Character uppercase conversion. **/
char UCaseChar(char ch){
    return ch >= 'a' && ch <= 'z' ? ch - 32: ch;
}

/** Text uppercase conversion. **/
char *UCase(char *text){
    int index;
    char *result = (char *) malloc(strlen(text+1) * sizeof(char));
    for (index = 0; *(text + index) != '\0'; index++) *(result + index) = UCaseChar(*(text + index));
    *(result + index) = '\0';
    return(result);
}