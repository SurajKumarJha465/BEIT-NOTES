/** Structure that illustrates the bit padding. **/
#include<stdio.h>

/**
	Description of Structure padding:
	gender: is of char type, 1 byte.[4 bytes after padding.]	
	age: is of int, 4 bytes. [4 bytes]
	name: is of 17 chars, 17 bytes. [20 bytes after padding]
	Total: 1 + 4 + 17 = 22 bytes, but 6 bytes are used for padding.
**/
struct Student {
	char gender;	
	int age;
	char name[17];
};

int main(){
	printf("Size of struct Student : %ld\n", sizeof(struct Student));
	return 0;
}

//Output:
//Size of struct Student : 28

