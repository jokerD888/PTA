#define _CRT_SECURE_NO_WARNINGS 1

//7 - 19 ºÚµ•º∆À„∆˜
//#include<stdio.h>
//int main(void)
//{
//	int num,sum=0,sign=0;
//	char c;
//	scanf("%d",&sum);
//	while(scanf("%c",&c))
//	{
//
//		switch(c)
//		{
//			case '+':scanf("%d",&num);sum+=num;break;
//			case '-':scanf("%d",&num);sum-=num;break;
//			case '*':scanf("%d",&num);sum*=num;break;
//			case '/':scanf("%d",&num);
//				if (num == 0)
//				{
//					sign = 1;
//				}
//			else
//			{
//				sum/=num;
//			}
//			break;
//			case '=':
//				if(sign)
//				printf("ERROR\n"); 
//				else
//				printf("%d\n",sum);return 0;
//			default :printf("ERROR\n");return 0;
//		}
//		
//	}
//	return 0;
// }


//7 - 20 —°‘Ò∑®≈≈–Ú
//#include<stdio.h>
//#include<stdlib.h>
//void Sort(int* p,int n)
//{
//	int i=0,j=0;
//	int max=0,k=0;
//	for(i=0;i<n-1;i++)
//	{
//		max=*(p+i);
//		k=i;
//		for(j=i+1;j<n;j++)
//		{
//			if(*(p+j)>max)
//			{
//				max=*(p+j);
//				k=j; 
//			}
//			
//		}
//		int tmp=*(p+i);
//		*(p+i)=*(p+k);
//		*(p+k)=tmp;
//	}
//}
//int main(void)
//{
//	int n=0,i=0;
//	scanf("%d",&n);
//	int *p=(int*)malloc(sizeof(int)*n);
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",(p+i));
//	}
//	Sort(p,n);
//	for(i=0;i<n-1;i++)
//	{
//		printf("%d ",*(p+i));
//	}
//	printf("%d\n",*(p+i));
//	return 0;
//}

//7 - 21 ’“∞∞µ„
#include<stdio.h>
#include<stdlib.h>
int Find(int* p, int n, int* x, int* y)
{
	int i = 0, j = 0;
	int row=0, col=0;
	int sign = 1;
	for (i = 0; i < n; i++)
	{
		int max = *(p+i*n);
		row = i;
		col = 0;
		for (j = 1; j < n; j++)
		{
			if (*(p + i * n + j)>max)
			{
				max = *(p + i * n + j);
				/*col = j;
				row = i;*/

			}
		}
		for (j = 0; j < n; j++)
		{
			sign = 1;
			if (max == *(p + i * n + j))
			{
				row = i; 
				col = j;
				for (int i1 = 0; i1 < n; i1++)
				{
					if (*(p + row * n + col) > *(p + i1 * n + col))
					{
						sign = 0;
						break;
					}
				}
				if (sign)
				{
					*x = row;
					*y = col;
					return 1;
				}
			}
		}
		
	}
	return 0;
}
int main(void)
{
	int n = 0, i = 0,j=0;
	int x, y;
	scanf("%d", &n);
	int* p = (int*)malloc(n*n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", (p + i * n + j));
		}
	}
	int ret=Find(p, n, &x, &y);
	
	if (ret)
		printf("%d %d", x, y);
	else
		printf("NONE\n");
	free(p);
	return 0;
}