#define _CRT_SECURE_NO_WARNINGS 1
//7 - 5 Shuffling Machine
// 指针数组
//#include<stdio.h>
//int main(void)
//{
//    int K = 0, i = 0;
//    char* card[55] = {"\0", "S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
//                   "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
//                   "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
//                   "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2" };
//    int arr[55] = { 0 };
//    int order[55] = { 0 };
//    int swap[55] = { 0 };
//    for (i = 1; i < 55; i++)
//    {
//        arr[i] = i;
//    }
//    scanf("%d", &K);
//    for (i = 1; i < 55; i++)
//    {
//        scanf("%d", &order[i]);
//    }
//    while (K--)
//    {
//        for (i = 1; i < 55; i++)
//        {
//            swap[order[i]] = arr[i];
//
//            //int tmp = arr[i];
//            //arr[i] = arr[order[i]];
//            //arr[order[i]] = tmp;
//        }
//        for (i = 1; i < 55; i++)
//        {
//            arr[i] = swap[i];
//        }
//    }
//
//    for (i = 1; i < 54; i++)
//    {
//        printf("%s ", card[swap[i]]);
//    }
//    printf("%s\n", card[swap[i]]);
//
//    return 0;
//}

//7 - 6 找出最小值
//#include<stdio.h>
//#include<stdlib.h>
//int FindMin(int* arr, int n)
//{
//    int min = arr[0], i;
//    for (i = 1; i < n; i++)
//    {
//        if (arr[i] < min)
//            min = arr[i];
//    }
//    return min;
//}
//int main(void)
//{
//    int n = 0, i;
//    scanf("%d", &n);
//    int* arr = (int*)malloc(n * sizeof(int));
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int ret = FindMin(arr, n);
//    printf("min = %d\n", ret);
//    return 0;
//}

//7 - 7 统计素数并求和
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	int M, N,j,n=0;
//	int sum = 0;
//	scanf("%d%d", &M, &N);
//	//若M<2，0和1都不是素数，直接忽略，从2开始计算，若N也小于2，则无法进入循环，输出也符合题目要求
//	if (M < 2) M = 2;
//	for (int i = M; i <= N; i++)
//	{
//		int r = sqrt(i);
//		for ( j = 2; j <= r; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (j > r)
//		{
//			n++;
//			sum += i;
//		}
//	}
//	printf("%d %d\n", n, sum);
//	return 0;
//}


//7 - 8 求幂级数展开的部分和
//当x取最大值5时无法通过测试
//#include<stdio.h>
//#include<math.h>
//long long Fact(int i)
//{
//	long long sum = 1;
//	for (int j = 2; j <= i; j++)
//	{
//		sum *= j;
//	}
//	return sum;
//}
//int main(void)
//{
//	double x = 0;
//	double sum = 0;
//	int i = 0;
//	scanf("%lf", &x);
//	double ret=pow(x, i) / Fact(i);
//	while (ret >= 0.00001)
//	{
//		sum += ret;
//		i++;
//		ret = pow(x, i) / Fact(i);
//	}
//	
//	sum += ret;
//	printf("%.4f", sum);
//	return 0;
//}

//完成版,不再设置变量保存阶乘的结果，而是直接连续计算
#include<stdio.h>
int main(void)
{
	double x, sum = 1.0,ret=1.0;//当x取最小值时,求和的第一项也为1;
	scanf("%lf", &x);
	for (int i = 1;; i++)
	{
		ret = (ret * x) / i;
		sum += ret;
		if (ret < 1e-5)//0.00001
			break;

	}
	printf("%.4lf", sum);
	return 0;
}

