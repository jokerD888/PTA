#define _CRT_SECURE_NO_WARNINGS 1
//7-1��ӡɳ©
//#include<stdio.h>
//int main(void)
//{
//	int n = 0;
//	char c = 0;
//	scanf("%d %c", &n,&c);
//	int row = 1;
//	//�������Ȳ�������ͣ�
//	//row=pow((n+1)/2,0.5);
//	//��
//	while (2 * row * row - 1 <=n)
//	{
//		row++;
//	}
//	--row;
//	
//	int i = 0;
//	for (i = row; i > 0; i--)
//	{
//		int j = 0;
//		for (j = 0; j < row - i; j++)
//			printf(" ");
//		for (j = 2*i-1; j > 0; j--)
//			printf("%c", c);
//		
//		printf("\n");
//	}
//
//	for (i = 1; i < row; i++)
//	{
//		int j = 0;
//		for (j = 1; j <row -i; j++)
//			printf(" ");
//		for (j = 0; j < 2 * i+1; j++)
//			printf("%c", c);
//
//		printf("\n");
//	}
//	int have = 0;
//	if (row == 0)
//		have = 0;
//	else
//	    have = n - 2 * row * row + 1;
//	printf("%d\n", have);
//	return 0;
//}


//7 - 2 �����Բ���
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//	int N = 0;
//	scanf("%d", &N);
//	int i = 0, j = 0, d, sum = 0;
//	int prev = 2;
//	int cur = 0;
//	int r = 0;
//	for (i = 3; i <=N; i++)
//	{
//		r = sqrt(i);
//		for (j =2; j <= r; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (j > r)
//		{
//			cur = i;
//			d = cur - prev;
//			if (d == 2)
//				sum++;
//			prev = cur;
//
//		}
//
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//7 - 3 ����Ԫ��ѭ����������

//#include<stdio.h>
//#include<stdlib.h>
//void reverse(int* nums, int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		++left;
//		--right;
//	}
//}
//void rotate1(int* nums, int numsSize, int k)
//{
//	int i = 0;
//	while (i < k)
//	{
//		//1 2 3 4 5 6 7
//		int tmp = nums[numsSize - 1];//�ȱ������һ��Ԫ��
//		//ǰ(numsSize-1)��Ԫ���Ⱥ��ƶ�һλ
//		int j = 0;
//		for (j = numsSize - 1; j > 0; j--)
//		{
//			nums[j] = nums[j - 1];
//		}
//		//�ٰ�����������һ��Ԫ�ط�����λ��
//		nums[0] = tmp;
//		i++;
//	}
//
//}
//int main(void)
//{
//	int N,M;
//	scanf("%d%d", &N,&M);
//	if (M > N)
//		M=M%N;
//	int* arr = (int*)malloc(N * sizeof(int));
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	rotate1(arr, N, M);
//	for (i = 0; i < N-1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("%d\n", arr[i]);
//	return 0;
//}


//7 - 4 Have Fun with Numbers
#include<stdio.h>
#include<string.h>
void Check(char* arr1, char* arr2)
{
    int i = 0;
    while (arr2[i] != '\0')
    {
        int j = 0;
        while (arr1[j] != '\0')
        {
            if (arr2[i] == arr1[j])
            {
                arr1[j] = 'A';
                break;
            }
            j++;
        }
        i++;
    }
}
int main(void)
{
    char arr1[21] = { 0 };
    char arr2[22] = { 0 };
    int n = 0;


    int i = 0,sign=0;
    scanf("%s", arr1);
    int len1 = strlen(arr1);
    if (arr1[0] >= '5')
         sign = 1;
        
    int next = 0;
    for (int j = len1-1; j >=0; j--)
    {
        int ret = 2 * (arr1[j]-'0');
        if (ret < 10)
        {
            arr2[j + sign] = ret + next+'0';
            next = 0;
        }
        else
        {
            ret %= 10;
            arr2[j + sign] = ret + next+'0';
            next = 1;
            
        }
        
    }
    if (next == 1)
    {
        arr2[0] = 1+'0';
    }

    Check(arr1, arr2);

    for (i = 0; i < len1; i++)
    {
        if (arr1[i] < 'A')
            break;
    }
    
    if (i < len1 || sign)
        printf("No\n");
    else
    {
        printf("Yes\n");
        
    }
    printf("%s\n", arr2);
        return 0;
}