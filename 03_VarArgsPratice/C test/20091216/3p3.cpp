#include <stdio.h>
#include <stdlib.h>

int main()
{
	float FHeight = 0.0F;
	float FWeight = 0.0F;
	float FBMI = 0.0F;

	while (FHeight > 2.5 || FHeight <=0)
	{
		printf("請輸入您的身高(單位:公尺)\n");
		scanf("%f", &FHeight);
		if (FHeight > 2.5 || FHeight <=0)	printf("身高輸入錯誤!\n");
	}
	while (FWeight > 300 || FWeight<=0)
	{
		printf("請輸入您的體重(單位:公斤)\n");
		scanf("%f", &FWeight);
		if (FWeight > 300 || FWeight<=0)	printf("體重輸入錯誤!\n");
	}

	FBMI = FWeight / (FHeight * FHeight);

	/*if (18.5 > FBMI)	printf("BMI值:%4.2f, 您太瘦了!!\n", FBMI);	// BMI < 18.5
	else if (27 <= FBMI)	printf("BMI值:%4.2f, 您太胖了!!\n", FBMI);	// BMI >= 27
	else if (18.5 <= FBMI && 24 > FBMI)	printf("BMI值:%4.2f, 您的體重標準!!\n", FBMI);	// 18.5 <= BMI < 24
	else	printf("BMI值:%4.2f, 您的體重有點重!!\n", FBMI);	// 24 <= BMI < 27*/

	if (18.5 > FBMI)	printf("BMI值:%4.2f, 您太瘦了!!\n", FBMI);	// BMI < 18.5
	else if (24 > FBMI)	printf("BMI值:%4.2f, 您的體重標準!!\n", FBMI);	// 18.5 <= BMI < 24
	else if (27 > FBMI)	printf("BMI值:%4.2f, 您的體重有點重!!\n", FBMI);	// 24 <= BMI < 27
	else printf("BMI值:%4.2f, 您太胖了!!\n", FBMI);	// BMI >= 27
	// 使用siwtch, type不能是float, 只能是int
	/*switch (FBMI)
	{
		case < 18.5:
			printf("BMI值:%4.2f, 您太瘦了!!\n", FBMI);	// BMI < 18.5
			break;
		case < 24:
			printf("BMI值:%4.2f, 您的體重標準!!\n", FBMI);	// 18.5 <= BMI < 24
			break;
		case < 27:
			printf("BMI值:%4.2f, 您的體重有點重!!\n", FBMI);	// 24 <= BMI < 27
			break;
		case >27:
			printf("BMI值:%4.2f, 您太胖了!!\n", FBMI);	// BMI >= 27
			break;
		default:
			printf("無BMI值\n");
	}*/


	system("PAUSE");
	return 0;
}