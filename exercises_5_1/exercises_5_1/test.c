#define _CRT_SECURE_NO_WARNINGS 1

//7 - 40 圆形体体积计算器
//#include<stdio.h>
//void Display()
//{
//	printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
//}
//void Ball()
//{
//
//	printf("Please enter the radius:\n");
//	double r = 0;
//	scanf("%lf", &r);
//	printf("%.2lf\n", 4 / 3.0 * 3.1415926535 * r * r * r);
//}
//void Cylinder()
//{
//
//	printf("Please enter the radius and the height:\n");
//	double r = 0, h = 0;
//	scanf("%lf%lf", &r, &h);
//	printf("%.2lf\n", 3.1415926535 * r * r * h);
//}
//void Cone()
//{
//
//	printf("Please enter the radius and the height:\n");
//	double r = 0, h = 0;
//	scanf("%lf%lf", &r, &h);
//	printf("%.2lf\n", 3.1415926535 * r * r * h/3);
//}
//int main(void)
//{
//
//	int input = 0;
//	do
//	{
//		Display();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Ball();
//			break;
//		case 2:
//			Cylinder();
//			break;
//		case 3:
//			Cone();
//			break;
//		default:
//			return 0;
//		}
//	} while (input);
//	return 0;
//}



//7 - 41 二分法求多项式单根
#include<stdio.h>


double a0, a1, a2, a3;
double FindRoot(double x)
{
	double y= a3 * x * x * x + a2 * x * x + a1 * x + a0;
	return y;
}
int main(void)
{
	
	double a, b,y,left,right,mid;

	scanf("%lf%lf%lf%lf", &a3, &a2, &a1, &a0);
	scanf("%lf%lf", &a, &b);

	left = a, right = b;
	while (left<=right-0.001  && FindRoot(left)*FindRoot(right)<=0)
	{
		if (FindRoot(left) == 0)
		{
			printf("%.2lf", left);
			return 0;
		}
		if (FindRoot(right) == 0)
		{
			printf("%.2lf", right);
			return 0;
		}
		mid = (left + right) / 2;
		y = FindRoot(mid);
		if (y == 0)
		{
			printf("%.2lf\n", mid);
			return 0;
		}
		else if (FindRoot(left) *y > 0)
		{
			left = mid;
		}
		else if(FindRoot(right) * y > 0)
		{
			right = mid;
		}
	}
	printf("%.2lf\n", mid);
	
	return 0;
}



//#include <stdio.h>
//float f(float x);
//float a3, a2, a1, a0;
//
//int main()
//{
//	float a, b;
//	scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
//	scanf("%f %f", &a, &b);
//	float left, mid, right;
//	left = a;
//	right = b;
//	while (left <= right - 0.001 && f(left) * f(right) <= 0)
//	{
//		if (f(left) == 0)
//		{
//			printf("%.2f", left);
//			return 0;
//		}
//		if (f(right) == 0)
//		{
//			printf("%.2f", right);
//			return 0;
//		}
//		mid = (left + right) / 2;
//		if (f(mid) * f(left) > 0)
//		{
//			left = mid;
//		}
//		else
//		{
//			right = mid;
//		}
//	}
//	printf("%.2f", mid);
//	return 0;
//}
//
//float f(float x)
//{
//	float result;
//	result = a3 * x * x * x + a2 * x * x + a1 * x + a0;
//	return result;
//}
