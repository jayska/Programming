#include <stdio.h>

int main()
{
	long int NumA = 2L;
	float NumB = 2.0;
	int NumC = 2;
	float NumD = 2.0F;

	printf("給定型態\n");
	printf("sizeof long int NumA(%d) = %d\n", NumA, sizeof(NumA));
	printf("sizeof float NumB(%f) = %d\n", NumB, sizeof(NumB));
	printf("sizeof int NumC(%d) = %d\n", NumC, sizeof(NumC));
	printf("sizeof float NumD(%f) = %d\n", NumD, sizeof(NumD));
	printf("*******************************************\n");
	printf("直接帶數字\n");
	printf("sizeof NumA(%d) = %d\n", 2L, sizeof(2L));
	printf("sizeof NumB(%f) = %d\n", 2.0, sizeof(2.0));
	printf("sizeof NumC(%d) = %d\n", 2, sizeof(2));
	printf("sizeof NumD(%f) = %d\n", 2.0F, sizeof(2.0F));

	getchar();
	return 0;
}