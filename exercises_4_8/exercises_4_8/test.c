#define _CRT_SECURE_NO_WARNINGS 1


//7 - 15 找出不是两个数组共有的元素
//#include<stdio.h>
//int Seek(int* arr1, int n1, int* arr2, int n2, int* arr3)
//{
//	int i = 0, j = 0, sign, k = 0, m = 0;
//	for (i = 0; i < n1; i++)
//	{
//		sign = 0;
//		for (j = 0; j < n2; j++)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				sign = 1;
//				break;
//			}
//		}
//		if (sign == 0)
//		{
//			arr3[k] = arr1[i];
//			k++;
//		}
//	}
//	for (i = 0; i < n2; i++)
//	{
//		sign = 0;
//		for (j = 0; j < n1; j++)
//		{
//			if (arr2[i] == arr1[j])
//			{
//				sign = 1;
//				break;
//			}
//		}
//		if (sign==0)
//		{
//			arr3[k] = arr2[i];
//			k++;
//		}
//	}
//	for (i = 0; i < k; i++)
//	{
//		for (j = i+1; j < k; j++)
//		{
//			if (arr3[i] == arr3[j])
//			{
//				for (m = j; m < k-1; m++)
//				{
//					arr3[m] = arr3[m + 1];
//				}
//				k--;
//			}
//		}
//	}
//	return k;
//}
//int main(void)
//{
//	int arr1[20] = { 0 };
//	int arr2[20] = { 0 };
//	int arr3[40] = { 0 };
//	int N1 = 0, N2 = 0;
//	scanf("%d", &N1);
//	int i = 0;
//	for (i = 0; i < N1; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	scanf("%d", &N2);
//
//	for (i = 0; i < N2; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//
//	int ret = Seek(arr1, N1, arr2, N2, arr3);
//	for (i = 0; i < ret - 1; i++)
//	{
//		printf("%d ", arr3[i]);
//	}
//	printf("%d\n", arr3[i]);
//
//	return 0;
//}


//7 - 16 矩阵运算
//#include<stdio.h>
//int Sum(int* p, int n)
//{
//	int i, j, sum = 0,S=0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (j== n - 1 || i == n - 1 || i + j == n - 1)
//			{
//				sum += *(p + i * n + j);
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			S += *(p + i * n + j);
//		}
//	}
//	return S - sum;
//}
//int main(void)
//{
//	int n = 0,i=0,j=0;
//	scanf("%d", &n);
//	int* p = (int*)malloc(n * n * sizeof(int));
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", (p+i*n+j));
//		}
//	}
//	int ret=Sum(p, n);
//	printf("%d\n", ret);
//	return 0;
//}

//7 - 17 方阵循环右移
#include<stdio.h>
void Move(int* p, int m,int n)
{
	int i = 0, j = 0,k;
	for (i = 0; i < n; i++)
	{
		k = m;
		while (k--)
		{
			int tmp = *(p + i * n + n - 1);
			for (j = n - 1; j > 0; j--)
			{
				*(p + i * n + j) = *(p + i * n + j - 1);
			}
			*(p + i * n + j) = tmp;
		}
	}
}
int main(void)
{
	int m=0,n = 0,i=0,j=0;
	scanf("%d%d", &m,&n);
	int* p = (int*)malloc(n * n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", (p+i*n+j));
		}
	}
	m %= n;
	Move(p, m,n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", *(p + i * n + j));
		}
		printf("\n");

	}
	free(p);
	return 0;
}