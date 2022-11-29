#include <stdio.h>
#include <math.h>
#define PI 3.1415 // PI 값 정의

double Degree_L(double L1, double L3, double d) // 왼쪽 초음파 센서의 L1, L3, d 값
{
	
	double D1 = 0; // D1(각도) 변수 선언 및 초기화
	double Lm = 0; // Lm(변) 변수 선언 및 초기화

	Lm = L3 - L1; // 변 Lm 표현

	D1 = atan(d / Lm); // 각도 D1 표현
	D1 *= (180 / PI); // 라디안에서 각도로 변환

	return D1;
}

double Degree_R(double L2, double L4, double d) // 오른쪽 초음파 센서의 L2, L4, d 값
{
	double D2 = 0; // D2(각도) 변수 선언 및 초기화
	double Ln = 0; // Lm(변) 변수 선언 및 초기화

	Ln = L2 - L4; // 변 Lm 표현

	D2 = atan(L2 - L4 / d); // 각도 D1 표현
	D2 *= (180 / PI); // 라디안에서 각도로 변환
	
	return D2;
}

int main(void)
{
	double D1 = 0, D2 = 0; 

	D1 = Degree_L(10, 20, 25); // L!, L3 , d 값 대입
	printf("D1 : %lf \n", D1); // D1 값 출력

	D2 = 90 - D1; // D2 = 90도 - D!
	printf("D2 : %lf\n", D2); // D2값 출력

	return 0;
}
