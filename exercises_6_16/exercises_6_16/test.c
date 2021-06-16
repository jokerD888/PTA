#define _CRT_SECURE_NO_WARNINGS 1

//7 - 69 打印n个 = 号
//#include<stdio.h>
//int main(void)
//{
//	int i, n;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		printf("=");
//	}
//	return 0;
//}


//7 - 70 求n！
//#include<stdio.h>
//int main(void)
//{
//	int i, n;
//	int sum = 1;
//	scanf("%d", &n);
//	for (i = 2; i <= n; i++)
//	{
//		sum *= i;
//	}
//
//	printf("%d", sum);
//	return 0;
//
//}


//7-71 逆序输出数的各位数字
//#include<stdio.h>
//int main(void)
//{
//	int n;
//	scanf("%d", &n);
//	while (n)
//	{
//		printf("%d", n % 10);
//		n /= 10;
//	}
//	return 0;
//}


//7 - 72 数组中能被5整除的数的和
//#include<stdio.h>
//int main(void)
//{
//	int arr[10];
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] % 5 == 0)
//			sum += arr[i];
//	}
//
//	printf("%d", sum);
//	return 0;
//}


//7 - 73 最高分、最低分、平均分
//#include<stdio.h>
//int main(void)
//{
//	int score[6];
//	int max, min, avg=0;
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", &score[i]);
//	}
//	max = min = score[0];
//	for (int i = 0; i < 6; i++)
//	{
//		if (score[i] > max)
//			max = score[i];
//		if (score[i] < min)
//			min = score[i];
//		avg += score[i];
//	}
//	printf("max:%d\nmin:%d\navg:%d", max, min, avg / 6);
//	return 0;
//}

//7 - 74 删除字符串中指定字符
//#include<stdio.h>
//int main(void)
//{
//	char str[21];
//	gets(str);
//	char c;
//	c=getchar();
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		if (str[i] == c)
//		{
//			memmove(&str[i], &str[i + 1], (21 - i) * sizeof(char));
//		}
//
//		++i;
//	}
//	puts(str);
//	return 0;
//}


//7 - 75 复制n个字符
#include<stdio.h>
char* my_strcpy(char* str, int n)
{
	char* arr = (char*)malloc(sizeof(char) * (n+1));
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = str[i];
	}
	arr[i] = '\0';

	return arr;
}
int main(void)
{
	char str[21];
	gets(str);
	int n;
	scanf("%d", &n);
	puts(my_strcpy(str, n));
	return 0;
}