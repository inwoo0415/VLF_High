#include <stdio.h>
#include <math.h>
#define PI 3.1415 // PI �� ����

double Degree_L(double L1, double L3, double d) // ���� ������ ������ L1, L3, d ��
{
	
	double D1 = 0; // D1(����) ���� ���� �� �ʱ�ȭ
	double Lm = 0; // Lm(��) ���� ���� �� �ʱ�ȭ

	Lm = L3 - L1; // �� Lm ǥ��

	D1 = atan(d / Lm); // ���� D1 ǥ��
	D1 *= (180 / PI); // ���ȿ��� ������ ��ȯ

	return D1;
}

double Degree_R(double L2, double L4, double d) // ������ ������ ������ L2, L4, d ��
{
	double D2 = 0; // D2(����) ���� ���� �� �ʱ�ȭ
	double Ln = 0; // Lm(��) ���� ���� �� �ʱ�ȭ

	Ln = L2 - L4; // �� Lm ǥ��

	D2 = atan(L2 - L4 / d); // ���� D1 ǥ��
	D2 *= (180 / PI); // ���ȿ��� ������ ��ȯ
	
	return D2;
}

int main(void)
{
	double D1 = 0, D2 = 0; 

	D1 = Degree_L(10, 20, 25); // L!, L3 , d �� ����
	printf("D1 : %lf \n", D1); // D1 �� ���

	D2 = 90 - D1; // D2 = 90�� - D!
	printf("D2 : %lf\n", D2); // D2�� ���

	return 0;
}
