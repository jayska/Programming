#include <stdio.h>
#include <stdlib.h>

int len(int La, int Lb)
{
	int Len = La - Lb;
	return (0 <= Len) ? Len : -(Len); 
}

int main()
{
	int Iax = 0;
	int Iay = 0;
	int Ibx = 0;
	int Iby = 0;
	int LenX = 0;
	int LenY = 0;

	printf("�п�Jone pointer(x1,y1):\n");
	//scanf("%d %d", &Iax, &Iay);
	printf("x1=");
	scanf("%d", &Iax);
	printf("y1=");
	scanf("%d", &Iay);
	
	printf("�п�Jtwo pointer(x2,y2):\n");
	//scanf("%d %d", &Ibx, &Iby);
	printf("x2=");
	scanf("%d", &Ibx);
	printf("y2=");
	scanf("%d", &Iby);

	LenX = len(Iax, Ibx);
	LenY = len(Iay, Iby);
	//LenX = ((Iax - Ibx) >= 0) ? (Iax -Ibx) : -(Iax - Ibx);
	//LenY = ((Iay - Iby) >= 0) ? (Iay - Iby) : -(Iay - Iby);
	if (LenX == 0 || LenY == 0)	printf("enter error!\n");
	else if (LenX == LenY)	printf("�����!\n");
	else	printf("�����!\n");
	/*if (len(Iax, Ibx) <= 0 || len(Iay, Iby) <= 0)	printf("��J���~\n");
	else if (len(Iax, Ibx) == len(Iay, Iby))	printf("���������\n");
	else printf("���������\n");*/
	/*if ((Iax - Ibx) == (Iay - Iby))
	{
		printf("���������\n");
	} else {
		printf("���������\n");
	}*/

	system("PAUSE");
	return 0;
}