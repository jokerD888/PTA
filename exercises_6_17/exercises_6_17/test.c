#define _CRT_SECURE_NO_WARNINGS 1
//7 - 76 判断闰年
//#include<stdio.h>
//int main(void)
//{
//	int n;
//	scanf("%d", &n);
//	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//		printf("yes");
//	else
//		printf("no");
//	return 0;
//}

//7 - 77 200以内各位数字之和为9的数的平均值
//#include<stdio.h>
//int main(void)
//{
//	int i,j;
//	int sum = 9;
//	int count = 1;
//	for (i = 10; i <= 200; i++)
//	{
//		int ret = i;
//		j = 0;
//		while (ret)
//		{
//			j += ret % 10;
//			ret /= 10;
//		}
//		if (j == 9)
//		{
//			sum += i;
//			++count;
//		}
//	}
//	printf("%.2lf", (double)sum/count);
//	return 0;
//}

//7 - 78 用数组存储并输出Fibonacci数列
//#include<stdio.h>
//int main(void)
//{
//	int arr[20];
//	int a = 1, b = 0,i;
//	for (i = 0; i < 20; i++)
//	{
//		arr[i] = a + b;
//		a = b;
//		b = arr[i];
//	}
//
//	for (i = 0; i < 20; i++)
//	{
//		printf("%10d", arr[i]);
//		if ((i + 1) % 5 == 0)
//			printf("\n");
//	}
//	return 0;
//}


//问题 u : ch——到底有多二
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[60];
	int i = 0,count=0;
	double d =1 , c = 1;;
	scanf("%s", str);
	int len = strlen(str);

	while (str[i] != '\0')
	{
		if (str[i] == '2')
			count++;
		++i;
	}
	if (str[len - 1] % 2 == 0)
		c = 2;
	if (str[0] == '-')
	{
		d =1.5;
		--len;
	}

	printf("%.2lf%%", (double)count /len * d * c * 100);
	return 0;
}