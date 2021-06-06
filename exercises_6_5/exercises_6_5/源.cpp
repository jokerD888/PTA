#define _CRT_SECURE_NO_WARNINGS 1
//7 - 55 数列求和 - 加强版
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	int a, n;
//	scanf("%d%d", &a, &n);
//	int arr[100007] = { 0 };
//	int i = 0;
//  //将n个数字对应的各个位相加，将大于10的部分+到arr的下一位，再将本位取余
//	for (i = 0; i < n; i++)
//	{
//		arr[i] += a * (n - i);
//		arr[i + 1] += arr[i] / 10;
//		arr[i] %= 10;
//	}
//
//	if (n == 0)
//		printf("0");
//	for (i = n; i >= 0; i--)
//	{
//		if (arr[n] == 0 && i == n) 
//		{
//			continue;
//		}
//		printf("%d",arr[i]);
//	}
//	
//	return 0;
//}



//7 - 56 求n以内最大的k个素数以及它们的和
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int issushu(int n)
{
	if (n == 1)
		return 0;
	int i = 1;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) break;
	}
	if (i > sqrt(n))
		return 1;
	return 0;
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	int sum = 0,i=0;
	int* arr = (int*)malloc(sizeof(int)*k);
	while (n)
	{
		if (issushu(n))
		{
			sum += n;
			arr[i] = n;
			i++;

		}

		if (i == k)
			break;
		--n;
	}
	for (int j = 0; j < i; j++)
	{
		if (j == i - 1)
			printf("%d=%d", arr[j], sum);
		else
		    printf("%d+", arr[j]);
	}
	return 0;
}
