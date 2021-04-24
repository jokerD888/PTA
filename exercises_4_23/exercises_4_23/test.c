#define _CRT_SECURE_NO_WARNINGS 1

//7 - 33 简易连连看
//#include<stdio.h>
//int main(void)
//{
//	int N = 0,sum=0;
//	scanf("%d", &N);
//	getchar();
//
//	int n = 2 * N, num = n*n;
//	int i,i1, j;
//	char* arr = (char*)malloc(sizeof(char) * n * n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%c", &arr[i * n + j]);
//			getchar();
//		}
//	}
//	int k = 0,x1,x2,y1,y2;
//	scanf("%d", &k);
//	for (i = 0; i < k; i++)
//	{
//		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//		
//		if (sum == 3)
//		{
//			printf("Game Over\n");
//			break;
//		}
//		x1--; x2--; y1--; y2--;
//		if (arr[x1 * n + y1] == arr[x2 * n + y2] && arr[x1 * n + y1]!='*')
//		{
//			arr[x1 * n + y1] = '*';
//			arr[x2 * n + y2] = '*';
//
//			num -= 2;
//			if (num == 0)
//			{
//				printf("Congratulations!\n");
//				break;
//			}
//			for (i1 = 0; i1 < n; i1++)
//			{
//				for (j = 0; j < n-1; j++)
//				{
//					printf("%c ", arr[i1 * n + j]);
//				}
//				printf("%c\n", arr[i1 * n + j]);
//
//			}
//			
//		}
//		else
//		{
//			sum++;
//			printf("Uh-oh\n");
//			
//		}
//	}
//	
//	return 0;
//}



//7 - 34 删除重复字符
//#include<stdio.h>
//int main(void)
//{
//	char arr[81] = { 0 };
//	gets(arr);
//	int num = 0, i = 0, j = 0, k = 0,x=0,a=0;
//	while (arr[i] != '\0')
//	{
//		num++;
//		i++;
//	}
//
//	for (i = 0; i < num - 1; i++)
//	{
//		k = i;
//		for (j = i+1; j < num; j++)
//		{
//			if (arr[j] < arr[k])
//				k = j;
//		}
//
//		if (k != i)
//		{
//			char tmp = arr[k];
//			arr[k] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//
//	i = 0, j = 1,k=0;
//	while (arr[i] != '\0')
//	{
//		k = 0, j = i + 1;;
//
//		if (arr[i] != arr[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			while (arr[i] == arr[j])
//			{
//				j++;
//				k++;
//			}
//			x = j;
//			while (arr[x] != '\0')
//			{
//				arr[x - k] = arr[x];
//				x++;
//			}
//			arr[x - k] = arr[x];
//		}
//			
//	}
//	puts(arr);
//	return 0;
//}


//7 - 35 统计字符出现次数
#include<stdio.h>
int main(void)
{
	char arr[81] = { 0 },c;
	gets(arr);
	scanf("%c", &c);
	int n = 0, i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			n++;
		i++;
	}
	printf("%d\n", n);
	
	return 0;
}