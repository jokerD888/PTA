#define _CRT_SECURE_NO_WARNINGS 1
//7 - 57 ����ѭ������
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



//7 - 58 ���ȫ����
//#include<stdio.h>
////c++��next_permutation(str.begin(),str.end())�˺���Ҳ�ɽ������
////�������dfs��ȱ���
//int a[10];
//int visited[10];///��¼ǰ���Ƿ����ظ������ֳ���
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
//			a[len++] = k;//�ѵ�ǰ�����ַŽ����飬���ұ����lenֵ��1
//			visited[k] = 1;//�ѵ�ǰ��������Ϊ1
//			perm(n, len);//�ݹ���ã������������룬����������len==n ���������Ȼ��ִ������Ļ�ԭ���
//			len--;//��Ϊ��ǰ��ε�lenֵ���˼�1 Ҫ��ԭ�����lenֵ����Ҫlen--��
//			visited[k] = 0;//�ѵ�ǰ���ֵı��ȥ����Ȼ�󷵻���һ�㣬����������ִ��
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


//7 - 59 ˧��û����
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
			scanf("%d", &j);//����Ȧֻ��һ������
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
	int ret = 1;//�Ƿ���˧��
	int* handsome = (int*)malloc(sizeof(int) * n);
	k = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &j);
		if (visited[j] == 0)
		{
			ret = 0;
			handsome[k++] = j;

			visited[j] = 1;//��ֹ������
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