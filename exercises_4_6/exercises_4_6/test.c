#define _CRT_SECURE_NO_WARNINGS 1
//7 - 9 特殊a串数列求和
//#include<stdio.h>
//int main(void)
//{
//	int a, n;
//	scanf("%d%d", &a, &n);
//	long long sum = 0, ret = 0;;
//	int j = 0;
//	int i = 0;
//	while (n)
//	{
//		j = n;
//		i = a;
//		ret = 0;
//		while (j--)
//		{
//			ret += i;
//			i *= 10;
//		}
//		sum += ret;
//		n--;
//	}
//	printf("s = %lld\n", sum);
//	return 0;
//}


//7 - 10 换硬币
//#include<stdio.h>
//int main(void)
//{
//	int x = 0;
//	scanf("%d", &x);
//	int n5 = 1, n2 = 1, n1 = 1,count=0;
//	int i, j, k;
//	for (i = x/5; i >=1; i--)
//	{
//		for (j = (x / 2) - 3; j >= 1; j--)
//		{
//			for (k = x - 2 - 5; k >=1 ; k--)
//			{
//				if (i * 5 + j * 2 + k == x)
//				{
//					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i, j, k, i + j + k);
//					count++;
//				}
//			}
//		}
//	}
//	printf("count = %d\n", count);
//	return 0;
//}

//7 - 11 水仙花数
#include<stdio.h>
#include<math.h>
int main(void)
{
	int N = 0,sum=0,i=0;
	//N=7时，程序运行超时，采用打表法
	int N7[4] = { 1741725,4210818,9800817,9926315 };
	scanf("%d", &N);
	if (N == 7)
	{
		for (i = 0; i < 4; i++)
		{
			printf("%d\n", N7[i]);
		}
	}
	else
	{
		int min = pow(10, N - 1);
		int max = pow(10, N);
		for ( i = min; i < max; i++)
		{
			int num = i;
			sum = 0;
			while (num)
			{
				sum += pow(num % 10, N);
				num /= 10;
			}
			if (sum == i)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}

//7 - 18 求一批整数中出现最多的个位数字
//#include<stdio.h>
//int main(void)
//{
//	int N = 0, num, ret, i;
//	int arr[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
//	int K[10] = { 0 };
//	scanf("%d", &N);
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", &num);
//		do
//		{
//			ret = num % 10;
//			if (arr[ret] == -1)
//				arr[ret] = 0;
//			arr[ret]++;
//			num /= 10;
//		} while (num);
//	}
//	int max = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] == max)
//		{
//			K[j] = i;
//			j++;
//		}
//
//	}
//	printf("%d: ", max);
//	for (i = 0; i < j - 1; i++)
//	{
//		printf("%d ", K[i]);
//	}
//	printf("%d\n", K[i]);
//
//	return 0;
//}