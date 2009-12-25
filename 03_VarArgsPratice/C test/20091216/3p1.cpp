#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int main()
{
	float FRang = 0;
	float Pi = 3.1416;

	printf("請輸入半徑, 一個大於0的數值:\nR=");
	scanf("%f", &FRang);
	//FRang = getch();		// 會以ASCII的方式儲存, 所以僅能輸入0~9數值
	//printf("FRang = %f\n", FRang);

	printf("圓的面積A=%6.2f\n", Pi*FRang*FRang);
	printf("圓的周長L=%6.2f\n", 2*Pi*FRang);

	system("PAUSE");
	return 0;
}