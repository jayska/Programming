#include <stdio.h>
#include <stdlib.h>

int main()
{
	float FHeight = 0.0F;
	float FWeight = 0.0F;
	float FBMI = 0.0F;

	while (FHeight > 2.5 || FHeight <=0)
	{
		printf("�п�J�z������(���:����)\n");
		scanf("%f", &FHeight);
		if (FHeight > 2.5 || FHeight <=0)	printf("������J���~!\n");
	}
	while (FWeight > 300 || FWeight<=0)
	{
		printf("�п�J�z���魫(���:����)\n");
		scanf("%f", &FWeight);
		if (FWeight > 300 || FWeight<=0)	printf("�魫��J���~!\n");
	}

	FBMI = FWeight / (FHeight * FHeight);

	/*if (18.5 > FBMI)	printf("BMI��:%4.2f, �z�ӽG�F!!\n", FBMI);	// BMI < 18.5
	else if (27 <= FBMI)	printf("BMI��:%4.2f, �z�ӭD�F!!\n", FBMI);	// BMI >= 27
	else if (18.5 <= FBMI && 24 > FBMI)	printf("BMI��:%4.2f, �z���魫�з�!!\n", FBMI);	// 18.5 <= BMI < 24
	else	printf("BMI��:%4.2f, �z���魫���I��!!\n", FBMI);	// 24 <= BMI < 27*/

	if (18.5 > FBMI)	printf("BMI��:%4.2f, �z�ӽG�F!!\n", FBMI);	// BMI < 18.5
	else if (24 > FBMI)	printf("BMI��:%4.2f, �z���魫�з�!!\n", FBMI);	// 18.5 <= BMI < 24
	else if (27 > FBMI)	printf("BMI��:%4.2f, �z���魫���I��!!\n", FBMI);	// 24 <= BMI < 27
	else printf("BMI��:%4.2f, �z�ӭD�F!!\n", FBMI);	// BMI >= 27
	// �ϥ�siwtch, type����Ofloat, �u��Oint
	/*switch (FBMI)
	{
		case < 18.5:
			printf("BMI��:%4.2f, �z�ӽG�F!!\n", FBMI);	// BMI < 18.5
			break;
		case < 24:
			printf("BMI��:%4.2f, �z���魫�з�!!\n", FBMI);	// 18.5 <= BMI < 24
			break;
		case < 27:
			printf("BMI��:%4.2f, �z���魫���I��!!\n", FBMI);	// 24 <= BMI < 27
			break;
		case >27:
			printf("BMI��:%4.2f, �z�ӭD�F!!\n", FBMI);	// BMI >= 27
			break;
		default:
			printf("�LBMI��\n");
	}*/


	system("PAUSE");
	return 0;
}