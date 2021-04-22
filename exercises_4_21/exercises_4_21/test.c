#define _CRT_SECURE_NO_WARNINGS 1
//7 - 30 Ã·É­Êý
//#include<stdio.h>
//#include<math.h>
//
//int Prime(int n)
//{
//	int i = 0;
//	int r = sqrt(n);
//	for (i = 2; i <= r; i++)
//	{
//		if (n % i == 0) break;
//	}
//
//	if (i > r)
//		return 1;
//	return 0;
//}
//int main(void)
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int sign = 1;
//	for (i = 2; i <=n; i++)
//	{
//		int num = pow(2, i) - 1;
//		int ret=Prime(num);
//		if (ret)
//		{
//			sign = 0;
//			printf("%d\n", num);
//		}
//	}
//	if (sign)
//		printf("None\n");
//	return 0;
//}



//7 - 31 ´òÓ¡Ñî»ÔÈý½Ç
//#include<stdio.h>
//
//int Tria(int row,int col)
//{
//	return (col == 1 || col == row) ? 1 : Tria(row - 1, col - 1) + Tria(row - 1, col);
//}
//int main(void)
//{
//	int N = 0;
//	int i = 0,j=0;
//	scanf("%d", &N);
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 0; j < N - i; j++)
//			printf("  ");
//		for (j = 1; j <= i; j++)
//		{
//			printf("%4d", Tria(i, j));
//		}
//		printf("\n");
//	}
//	return 0;
//}


//7 - 32 ÂÝÐý·½Õó

//#include<stdio.h>
//int Turn(int* arr, int n,int count,int number)
//{
//	/*int num = 1;
//	int i = 0, j = 0;
//	for (i = count; i < n-count; i++)
//	{
//		scanf("%d",num);
//		*(arr+i)=
//		num++;
//	}
//	for (i = count+1; i < n; i++)
//	{
//		j = n - 1-count;
//		scanf("%d", num);
//		num++;
//	}
//	for (j = n - 2; j >= 0; j--)
//	{
//		i = n - 2;
//		scanf("%d", (arr + i * n + j));
//	}
//	for (i = n - 1; i >0; i--)
//	{
//		scanf("%d", (arr + i * n));
//	}*/
//	int i = 0, j = 0;
//	j = count;
//	for (i = count; i < n-count; i++)
//	{
//		*(arr + i+j*n) = number;
//		number++;
//	}
//	j = i - 1;
//	for (i =count+1; i < n - count; i++)
//	{
//		*(arr + i * n + j) = number;
//		number++;
//	}
//	i--;
//	for (j--; j >= count; j--)
//	{
//		*(arr + i * n + j) = number;
//		number++;
//	}
//	j = count;
//	for (i--; i > count; i--)
//	{
//		*(arr + i * n + j) = number;
//		number++;
//	}
//	return number;
//}
//void Screw(int* arr, int n)
//{
//	int i = 0,j=0;
//	int y=n%2;
//	int number = 1;
//	int count = n / 2;
//	for (i = 0; i < count; i++)
//	{
//		number=Turn(arr, n,i,number);
//
//	}
//	if (y)
//		*(arr + count * n + count) = number;
//}
//int main(void)
//{
//	int N = 0;
//	int i = 0,j=0;
//	scanf("%d", &N);
//	int* arr = (int*)malloc(sizeof(int) * N * N);
//	Screw(arr, N);
//
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N; j++)
//		{
//			printf("%3d", *(arr + i * N + j));
//		}
//		printf("\n");
//
//	}
//	return 0;
//}

#include<stdio.h>
int main(void)
{
	int n = 0;
	scanf("%d", &n);	
	int i, j, x = 0, y = 0, c = n - 1,k=1;
	
	int* arr = (int*)malloc(sizeof(int) * n * n);
	for (i = 0; i < n / 2; i++)
	{
		for (j = 0; j < c; j++)
		{
			arr[x * n + y] = k++;
			y++;
		}
		for (j = 0; j < c; j++)
		{
			arr[x* n + y] = k++;
			x++;
		}
		for (j = 0; j < c; j++)
		{
			arr[x * n + y] = k++;
			y--;
		}
		for (j = 0; j < c; j++)
		{
			arr[x * n + y] = k++;
			x--;
		}
		x++;
		y++;
		c -= 2;
	}
	if (n % 2) arr[n / 2 * n + n / 2] = k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%3d", arr[i * n + j]);
		}
		printf("\n");
	}

	return 0;
}