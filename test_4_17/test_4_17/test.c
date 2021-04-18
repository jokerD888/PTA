#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char arr[2];
//	char arr1[3];
//	scanf("%s", arr);
//	//strcpy(arr1, arr);
//	printf("%s", _strupr(arr));
//	return 0;
//}




//7 - 25 通讯录排序
//#include<stdio.h>
//#include<string.h>
//struct People
//{
//	char name[11];
//	char birthday[9];
//	char nember[18];
//};
//typedef struct People Peop;
//void SortAge(Peop* arr,int n)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < n; i++)
//	{
//		int k = i;
//		for (j = i + 1; j < n; j++)
//		{
//			if (strcmp(arr[j].birthday, arr[k].birthday) < 0) 
//				k = j;
//		}
//
//		if (k != i)
//		{
//			Peop tmp;
//			tmp = arr[i];
//			arr[i] = arr[k];
//			arr[k] = tmp;
//		}
//
//	}
//}
//void PeopPrint(Peop* arr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%s %s %s\n", arr[i].name, arr[i].birthday, arr[i].nember);
//	}
//}
//
//int main(void)
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	getchar();
//	Peop* arr = (Peop*)malloc(sizeof(Peop) * n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", arr[i].name);
//		getchar();
//
//		scanf("%s", arr[i].birthday);
//		getchar();
//
//		scanf("%s", arr[i].nember);
//		getchar();
//
//	}
//	SortAge(arr,n);
//	PeopPrint(arr, n);
//	return 0;
//}



//7 - 26 求一元二次方程的根
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	float a, b, c;
//	double x1, x2;
//	scanf("%f %f %f", &a, &b, &c);
//	if (!a && !b && !c)
//	{
//		printf("Zero Equation\n");
//		return 0;
//	}
//	if (!a && !b && c)
//	{
//		printf("Not An Equation\n");
//		return 0;
//	}
//	if (!a)
//	{
//		x1 = -c / b;
//		printf("%.2f", x1);
//		return 0;
//	}
//	double judge = b * b - 4 * a * c;
//	if (judge == 0)
//	{
//		x1 = -b / (2 * a);
//		printf("%.2f\n", x1);
//	}
//	else if (judge > 0)
//	{
//		x1 = -(b + sqrt(judge)) / (2 * a);
//		x2= -(b - sqrt(judge)) / (2 * a);
//		printf("%.2f\n%.2f", x1 > x2 ? x1 : x2, x1 < x2 ? x1 : x2);
//	}
//	else
//	{
//		double s;
//		s = -b / (2 * a);
//		x1 = (sqrt(-judge)) / (2 * a);
//		x2 = (-sqrt(-judge)) / (2 * a);
//		if(s)
//		   printf("%.2f+%.2fi\n%.2f%.2fi\n",s, x1 > x2 ? x1 : x2,s, x1 < x2 ? x1 : x2);
//		else
//			printf("0.00+%.2fi\n0.00%.2fi\n",x1 > x2 ? x1 : x2,x1 < x2 ? x1 : x2);
//	}
//	return 0;
//}


//7 - 27 验证“哥德巴赫猜想”
#include<stdio.h>
#include<math.h>
int Prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main(void)
{
	int N;
	int i = 0;
	scanf("%d", &N);
	for (i = 2; i<= N - 2; i++)
	{
		if (Prime(i) && Prime(N - i))
		{
			printf("%d = %d + %d\n", N, i, N - i);
			break;
		}
	}
	return 0;
}