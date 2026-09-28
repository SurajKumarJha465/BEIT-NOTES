#include<stdio.h>

int compareStrings(char *, char *);
int getStringLength(char *);
char* strToupper(char*);

int compareStrings(char *a, char *b){
    int result = 0;
    while(*a != '\0' || *b != '\0'){
    	printf("Iteration : compare %c and %c.\n", *a, *b);
        if(*a > *b){
            return 1;
        }else if (*a < *b){
            return -1;
        }
        a++;b++;
    }
    if(*a != '\0'){
        return 1;
    }else if(*b != '\0'){
        return -1;
    }
    return result;
}

char *strToupper(char *str){
    int i = 0;
    char *rStr = (char*) malloc((strlen(str) + 1) * sizeof(char));
    for(; str[i]; ++i){
        if((str[i] >= 'a') && (str[i] <= 'z'))
            rStr[i] = str[i] + 'A' - 'a';
        else
            rStr[i] = str[i];
    }
    rStr[i] = '\0';
    return rStr;
}

int getStringLength(char *str){
    int result = 0;
    while(*str != '\0'){
        result ++;
        str++;
    }
    return result;
}

int main(){
    char *first = "appze";
    char *second = "apple";
    int result = compareStrings(first, second);

    first = strToupper(first);
    second = strToupper(second);

    printf("Comparison result : %d\n", result);
    printf("Length of %s = %d\n", first, getStringLength(first));
    printf("Length of %s = %d\n", second, getStringLength(second));
    return(0);
}
