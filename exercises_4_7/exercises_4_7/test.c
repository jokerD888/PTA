#define _CRT_SECURE_NO_WARNINGS 1
//7 - 12 高空坠球

//#include<stdio.h>
//int main(void)
//{
//	long h, n;
//	double s = 0, x = 0;
//
//	scanf("%ld%ld", &h, &n);
//	if (n > 0)
//	{
//		x = h;
//		while (n--)
//		{
//			s += x;
//			x /= 2.0;
//
//			if (n) s += x;
//		}
//	}
//	printf("%.1f %.1f\n", s, x);
//	return 0;
//}



//7 - 13 求最大值及其下标
//#include<stdio.h>
//int main(void)
//{
//	int n = 0,num,max,K=0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &num);
//		if (i == 0)
//			max = num;
//		else
//		{
//			if (num > max)
//			{
//				max = num;
//				K = i;
//			}
//		}
//	}
//
//	printf("%d %d\n", max, K);
//	return 0;
//}

//7 - 14 将数组中的数逆序存放
//#include<stdio.h>
//void Reverse(int* a, int n)
//{
//	int left = 0;
//	int right = n - 1;
//	while (left < right)
//	{
//		int tmp = a[left];
//		a[left] = a[right];
//		a[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main(void)
//{
//	int n = 0,i;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(n*sizeof(int));
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	Reverse(arr, n);
//	for (i = 0; i < n-1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("%d\n", arr[i]);
//	free(arr);
//
//	return 0;
//}

