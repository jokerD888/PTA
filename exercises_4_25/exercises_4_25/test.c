#define _CRT_SECURE_NO_WARNINGS 1

//7 - 36 装箱问题
//#include<stdio.h>
//int main(void)
//{
//	int n = 0,i=0,j;
//	int max = 0;
//	int box = 1;
//	int space[1000] = { 0 };
//	for (i = 0; i < 1000; i++)
//	{
//		space[i] = 100;
//	}
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) *  n);
//	i = 0;
//	while (n--)
//	{
//		scanf("%d", &arr[i]);
//		i++;
//	}
//	n = i ;
//
//	for(i=0;i<n;i++)
//	{
//		j = 0;
//		while (arr[i] > space[j])
//		{
//			j++;
//			if (j > max)
//				max = j;
//		}
//		space[j] -= arr[i];
//		printf("%d %d\n", arr[i],j+1);
//
//	}
//	printf("%d\n", max+1);
//	return 0;
//}



//7 - 37 组个最小数
//#include<stdio.h>
//int main(void)
//{
//	int arr[10] = { 0 };
//	int i = 0,sum=0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		sum += arr[i];
//	}
//	int* num = (int*)malloc(sizeof(int) * sum);
//	int first = 0;
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i] != 0)
//		{
//			first = i;
//			arr[i]--;
//			break; 
//		}
//	}
//	printf("%d", first);
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] != 0)
//		{
//			while (arr[i] != 0)
//			{
//				printf("%d",i);
//				arr[i]--;
//			}
//		}
//	}
//	printf("\n");
//	return 0;
//}


//7 - 38 IP地址转换
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	int i = 0,sum=0;
//	char arr[33] = { 0 };
//	gets(arr);
//	for (i = 0; i < 32; i++)
//	{
//		sum += (arr[i] - '0') * pow(2, 7 - i%8);
//		if ((i + 1) % 8 == 0)
//		{
//			if (i == 31)
//				printf("%d\n", sum);
//			else
//			    printf("%d.",sum);
//			sum = 0;
//		}
//	}
//	return 0;
//}



//7 - 39 找出总分最高的学生
#include<stdio.h>
struct score
{
	char number[10];
	char name[20];
	int arr[3];
	int sum;
};
typedef struct score score;
int main(void)
{
	score S[10] = { 0 };
	int n = 0,i=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s%s%d%d%d", S[i].number, S[i].name, &S[i].arr[0], &S[i].arr[1], &S[i].arr[2]);
		S[i].sum = S[i].arr[0] + S[i].arr[1] + S[i].arr[2];
	}
	int j = 0;
	int max = 0;
	for (i = 0; i < n; i++)
	{
		if (S[i].sum > max)
		{
			max = S[i].sum;
			j = i;
		}
	}
	printf("%s %s %d\n", S[j].name, S[j].number, S[j].sum);
	return 0;
}