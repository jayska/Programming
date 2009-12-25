#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	char ch;

	printf("Please enter a int number : \n");
	scanf("%d", &num);
	printf("Please enter a char : \n");
	scanf(" %c", &ch);
	printf("number = %d, ASCII of ch=%d\n", num, ch);

	system("PAUSE");
	return 0;
}