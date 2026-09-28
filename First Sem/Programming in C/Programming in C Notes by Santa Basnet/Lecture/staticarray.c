/** Example of Static array. **/

#include<stdio.h>

int main(){
	static char *names[10] = {
		"Ram",
		"Shyam",
		"Hari"
	};
	
	printf("%s\n", names[1]);
	
	return 0;
}
