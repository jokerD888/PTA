#define _CRT_SECURE_NO_WARNINGS 1

//7 - 28 ºÚ¶´Êý
//#include<stdio.h>
//
//int Max(int* arr)
//{
//	int i = 0;
//	for (i = 0; i < 2; i++)
//	{
//		int k = i;
//		int j = 0;
//		for (j = i+1; j < 3; j++)
//		{
//			if (arr[j] > arr[k])
//			{
//				k = j;
//			}
//		}
//		if (k != i)
//		{
//			int tmp = arr[k];
//			arr[k] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//
//	int sum = 0;
//	for (i = 0; i < 3; i++)
//	{
//		sum *= 10;
//		sum += arr[i] ;
//		
//	}
//	return sum;
//}
//
//int Min(int* arr)
//{
//	int i = 0;
//	for (i = 0; i < 2; i++)
//	{
//		int k = i;
//		int j = 0;
//		for (j = i + 1; j < 3; j++)
//		{
//			if (arr[j] < arr[k])
//			{
//				k = j;
//			}
//		}
//		if (k != i)
//		{
//			int tmp = arr[k];
//			arr[k] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//
//	int sum = 0;
//	for (i = 0; i < 3; i++)
//	{
//		sum *= 10;
//		sum += arr[i] ;
//		
//	}
//	return sum;
//}
//void reserve(int* arr, int n)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		arr[i] = n % 10;
//		n /= 10;
//	}
//}
//int main(void)
//{
//	int arr[3] = { 0 };
//	int i = 0;
//	int dvalue = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%1d", &arr[i]);
//	}
//	i = 1;
//	do
//	{
//		int max = Max(arr);
//		int min = Min(arr);
//		dvalue =max-min;
//		printf("%d: %d - %d = %d\n", i, max, min, dvalue);
//		i++;
//		reserve(arr,dvalue);
//	} while (dvalue && dvalue != 495);
//	return 0;
//}



//7 - 29 ÕÒÍêÊý
#include<stdio.h>

void Prenum(n, m)
{
	int i = 0,sign=0;
	int arr[100] = { 0 };
	for (i = n; i <= m; i++)
	{
		int j = 0, sum = 1;
		int k = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				arr[k] = j;
				k++;
				sum += j;
			}	
		}
		if (i == sum)
		{
			printf("%d = 1 + ", i);
			for (j = 0; j <k-1; j++)
			{
				printf("%d + ", arr[j]);
			}

			printf("%d\n", arr[k-1]);
			sign = 1;
		}
	}
	if (!sign)
	{
		printf("None\n");
	}
}

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	Prenum(n, m);
	return 0;
}