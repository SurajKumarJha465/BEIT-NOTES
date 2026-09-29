/* Variable and Constant demonstration program. */
#include <stdio.h>
#define MSG "Enter Your Name : "
int main()
{
	char Name[100];
	const float PI = 3.14159f;
	float G = 6.67e-11;
	int m_Char = 0x6D;
	printf(MSG);
	gets(Name);

	//scanf("%e", &G);
	printf("Hello %s!\n",Name);
	printf("Character m -> %d\t%X\n", m_Char, m_Char);
	printf("Pi & G -> %2.4f\t%e\n", PI, G);
	return(1);
}
