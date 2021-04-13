#define _CRT_SECURE_NO_WARNINGS 1
//7 - 22 字符串排序
//#include<stdio.h>
//int main(void)
//{
//	char arr[5][80] = { 0 };
//	int i = 0,j=0,k;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//	printf("After sorted:\n");
//	int x = 0;
//	for (i = 0; i < 4; i++)
//	{
//		x = 0;
//		for (j = 0; j < 5 - i; j++)
//		{
//			if (strcmp(arr[j], arr[x]) > 0)
//				x = j;
//		}
//
//			char s[80] = { 0 };
//			strcpy(s, arr[x]);
//			strcpy(arr[x], arr[4 - i]);
//			strcpy(arr[4 - i], s);
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	return 0;
//}


//7 - 23 输出学生成绩
//#include<stdio.h>
//int main(void)
//{
//	int N = 0;
//	int i = 0;
//	double aver, max, min;
//	scanf("%d", &N);
//	double* p = (double*)malloc(N * sizeof(double));
//	for (i = 0; i < N; i++)
//	{
//		scanf("%lf", (p + i));
//	}
//	aver=min = max = *p;
//
//	for (i = 1; i < N; i++)
//	{
//		if (*(p + i) > max)
//			max = *(p + i);
//		if (*(p + i) < min)
//			min = *(p + i);
//		aver += (*(p + i));
//	}
//
//	printf("average = %.2f\nmax = %.2f\nmin = %.2f\n", aver/N, max, min);
//	free(p);
//	p = NULL;
//	return 0;
//}


//7 - 24 查找书籍
#include<stdio.h>
typedef struct Book
{
	char s[31];
	double price;
}Book;
int main(void)
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	
	Book* library = (Book*)malloc(sizeof(Book) * n);
	for (i = 0; i < n; i++)
	{
		getchar();
		gets((library + i)->s);
		scanf("%lf", &((library + i)->price));
	}
	int min = 0, max = 0;
	max = min = library->price;
	int maxone = 0, minone = 0;
	for (i = 1; i < n; i++)
	{
		if ((library + i)->price > max)
		{
			max = (library + i)->price;
			maxone = i;
		}
		if ((library + i)->price < min)
		{
			min = (library + i)->price;
			minone = i;
		}
	}
	printf("%.2lf, ", (library + maxone)->price);
	puts((library + maxone)->s);
	printf("%.2lf, ", (library + minone)->price);
	puts((library + minone)->s);
	
	free(library);
	return 0;
}