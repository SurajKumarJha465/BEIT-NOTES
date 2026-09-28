/** File read/write with fread and fwrite.**/
#include<stdio.h>

static char fileName[100] = "filecontent.txt";


int main(){
	printf("Given file name : %s\n", fileName); 
	
	FILE *file;
	file = fopen(fileName, "w+");
	fprintf(file, "Hello World !\n");
	fclose(file);
	
	return 0;

}
