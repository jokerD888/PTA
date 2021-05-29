#define _CRT_SECURE_NO_WARNINGS 1

//7 - 50 有理数均值
//#include<stdio.h>
//int GY(int a, int b)
//{
//	int ret = 1;
//	while (b)
//	{
//		ret = a % b;
//		a = b;
//		b = ret;
//	}
//
//	return a;
//}
//int main(void)
//{
//
//	int n,i,ret;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * 2 * n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d/%d", &arr[i*2], &arr[i*2+1]);
//
//		ret = GY(arr[i * 2], arr[i * 2 + 1]);
//		arr[i * 2] /= ret;
//		arr[i * 2+1] /= ret;
//
//	}
//
//	int mu = 1;
//	for (i = 0; i < n; i++)
//		mu *= arr[i * 2 + 1];
//	int zi = 0;
//	for (i = 0; i < n; i++)
//	{
//		zi += (arr[i * 2] * (mu / arr[i * 2 + 1]));
//	}
//	if (zi == 0)//当分子为0时，在下面求最大公约数时会发生浮点错误
//	{
//		printf("0\n");
//		return 0;
//	}
//	mu*=n;
//	ret = GY(zi, mu);
//	zi /= ret;
//	mu /= ret;
//	if (mu==1)
//		printf("%d",zi);
//	else
//	{
//		printf("%d/%d", zi , mu);
//	}
//	return 0;
//}


//7-51 Consecutive Factors
#include<stdio.h>
int main(void)
{
	int n;
	int i, j;
	scanf("%d", &n);
	int first = 0, len = 0, maxn = sqrt(n) + 1;
	//first记录连乘的第一个数，len记录当前最大连续个数，maxn为最大因子

	for (i = 2; i <= maxn; i++)
	{
		int tmp = 1;
		for (j = i; j <= maxn; j++)
		{
			tmp *= j;
			if (n % tmp != 0)//当阶乘结果不能被n整除，说明连续因子到此停止，退出当前循环
				break;
		}

		if (j - i > len)//连续个数是否大于len
		{
			len = j - i;
			first = i;
		}

	}
		if (first == 0)//first=0 说明n是个质数
			printf("1\n%d", n);
		else
		{
			printf("%d\n",len);
			for (i = 0; i < len; i++)
			{
				printf("%d", first + i);
				if (i != len - 1)
					printf("*");
			}
		}
	
	return 0;
}