#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int main()
{
	float FRang = 0;
	float Pi = 3.1416;

	printf("�п�J�b�|, �@�Ӥj��0���ƭ�:\nR=");
	scanf("%f", &FRang);
	//FRang = getch();		// �|�HASCII���覡�x�s, �ҥH�ȯ��J0~9�ƭ�
	//printf("FRang = %f\n", FRang);

	printf("�ꪺ���nA=%6.2f\n", Pi*FRang*FRang);
	printf("�ꪺ�P��L=%6.2f\n", 2*Pi*FRang);

	system("PAUSE");
	return 0;
}