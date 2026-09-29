/** Read a line text using fgets from console.**/
#include<stdio.h>
#include<string.h>

#define SIZE 100

int main(){
	
	char lineText[SIZE];
	printf("Type your text here: \n");
	
	fgets(lineText, SIZE, stdin);
	
	printf("Your text: \n");
	fputs(lineText, stdout);
	
	printf("\nLength : %ld \n", strlen(lineText));	
	return 0;
}
