#define _CRT_SECURE_NO_WARNINGS 1

//7 - 63 求三角形面积
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	double a, b, c;
//	double p,S;
//	scanf("%lf,%lf,%lf", &a, &b, &c);
//	p = (a + b + c) / 2.0;
//	S = sqrt((p * (p - a) * (p - b) * (p - c)));
//
//	printf("%.2lf", S);
//	return 0;
//}


//7 - 64 斐波那契（Fibonacci）数列前20项
//#include<stdio.h>
//int main(void)
//{
//	int a = 1, b = 0,c,i;
//	for (i = 0; i < 20; i++)
//	{
//		c = a + b;
//		printf("%8d", c);
//		a = b;        
//		b = c;
//	}
//	return 0;
//}




//7 - 65 辗转相除法求最大公约数
//#include<stdio.h>
//int gcd(int a, int b)
//{
//	int ret ;
//	while (b)
//	{
//		ret = a % b;
//		a = b;
//		b = ret;
//	}
//	return a;
//}
//int main(void)
//{
//	int a, b;
//	scanf("%d,%d", &a, &b);
//	printf("gcd=%d", gcd(a, b));
//	return 0;
//}


//7 - 66 统计两整数间被3整除数的个数
//#include<stdio.h>
//int main(void)
//{
//	int a, b;
//	int n = 0;
//	scanf("%d %d", &a, &b);
//	for (int i = a; i <= b; i++)
//	{
//		if (i % 3 == 0)
//			n++;
//	}
//	printf("a=%d,b=%d,n=%d", a, b, n);
//	return 0;
//}


//7 - 67 回文数
//#include<stdio.h>
//int main(void)
//{
//	int arr[5];
//	scanf("%1d%1d%1d%1d%1d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
//	int left = 0;
//	int right = 4;
//	while (left < right)
//	{
//		if (arr[left] != arr[right])
//			break;
//
//		left++;
//		right--;
//	}
//	if (left < right)
//		printf("no");
//	else
//		printf("yes");
//	return 0;
//}

//7 - 68 判断是否构成三角形
#include<stdio.h>
int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
		printf("YES");
	else
		printf("NO");
	return 0;
}