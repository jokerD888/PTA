#define _CRT_SECURE_NO_WARNINGS 1
//7 - 57 数组循环左移
//#include<stdio.h>
//
//void reverse(int* arr, int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main(void)
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	m %= n;
//	int* arr = (int*)malloc(sizeof(int) * n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//		scanf("%d", arr + i);
//
//	reverse(arr, 0, m-1);
//	reverse(arr, m, n-1);
//	reverse(arr, 0, n-1);
//
//	for (i = 0; i < n - 1; i++)
//		printf("%d ", arr[i]);
//	printf("%d", arr[i]);
//
//	return 0;
//}



//7 - 58 输出全排列
//#include<stdio.h>
////c++中next_permutation(str.begin(),str.end())此函数也可解决此题
////此题采用dfs深度遍历
//int a[10];
//int visited[10];///记录前面是否有重复的数字出现
//
//void perm(int n, int len)
//{
//	int i, k;
//	if (len == n)
//	{
//		for (i = 0; i < n - 1; i++)
//			printf("%d", a[i]);
//		printf("%d\n", a[n - 1]);
//	}
//	for (k = 1; k <= n; k++)
//	{
//		if (visited[k] == 0)
//		{
//			a[len++] = k;//把当前的数字放进数组，并且本层的len值加1
//			visited[k] = 1;//把当前的数字置为1
//			perm(n, len);//递归调用，继续往下深入，如若满足了len==n 就做输出，然后执行下面的还原语句
//			len--;//因为当前层次的len值做了加1 要还原本层的len值，就要len--；
//			visited[k] = 0;//把当前数字的标记去掉，然后返回上一层，继续再往下执行
//		}
//	}
//
//}
//int main(void)
//{
//	int n;
//	scanf("%d", &n);
//	perm(n, 0);
//	return 0;
//}


//7 - 59 帅到没朋友
#include<stdio.h>
int main(void)
{
	int i = 0, j = 0, k = 0;
	int visited[100000];
	memset(visited,0, sizeof(int) * 100000);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &k);
		if(k==1)
			scanf("%d", &j);//朋友圈只有一个的人
		else
		{
			for (i = 0; i < k; i++)
			{
				scanf("%d", &j);
				visited[j] = 1;
			}
		}
	}

	scanf("%d", &n);
	int ret = 1;//是否有帅哥
	int* handsome = (int*)malloc(sizeof(int) * n);
	k = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &j);
		if (visited[j] == 0)
		{
			ret = 0;
			handsome[k++] = j;

			visited[j] = 1;//防止自恋狂
		}
	}
	for (i = 0; i < k; i++)
	{
		if(i==k-1)
			printf("%05d", handsome[i]);
		else
		    printf("%05d ", handsome[i]);
	}
	if (ret)
		printf("No one is handsome");
	return 0;
}