#define _CRT_SECURE_NO_WARNINGS 1

//7 - 44 ð�ݷ�����
//#include<stdio.h>
//void Bubsort(int* arr,int n,int k)
//{
//	int i, j;
//	for (i = 0; i < k; i++)
//	{
//		for (j = 0; j < n - i-1; j++)
//		{
//			if (*(arr + j) > *(arr + j + 1))
//			{
//				int tmp = *(arr + j);
//				*(arr + j) = *(arr + j + 1);
//				*(arr + j + 1) = tmp;
//			}
//		}
//	}
//}
//int main(void)
//{
//	int n, k;
//	scanf("%d%d", &n, &k);
//	int* arr = malloc(sizeof(int) * n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", (arr + i));
//	}
//	Bubsort(arr,n,k);
//	for (i = 0; i < n-1; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("%d\n", *(arr + i));
//
//	return 0;
//}



//7 - 45 ����ѡ����
//������ͨ�������������������뵽��ѭ�����к�ѭ���������һ��

//ѭ������ʵ��
//#include<stdio.h>
//int n;//ȫ�ֱ���
//typedef struct Queue
//{
//	int* base;
//	int rear;
//	int front;
//}Queue;
//void EnQueue(Queue* Q,int x)
//{
//	//��Ϊ�������Ԫ��ֻ���ٲ���࣬�ڴ˾Ͳ��ж�����
//	Q->base[Q->rear] = x;
//	Q->rear = (Q->rear + 1) % n;
//
//}
//int DeQueue(Queue* Q)
//{
//	int e = Q->base[Q->front];
//	Q->front = (Q->front + 1) % n;
//	return e;
//}
//int QueueLength(Queue* Q)
//{
//	return (Q->rear - Q->front + n) % n;
//}
//int Monkey1()
//{
//	Queue Q;
//	Q.base = (int*)malloc(n * sizeof(int));
//	Q.front = Q.rear = 0;
//	for (int i = 1; i < n; i++)
//	{
//		EnQueue(&Q, i);
//	}
//	int k = 0;
//
//	while (QueueLength(&Q) > 1)
//	{
//		k++;
//		if (k == 3)
//		{
//			DeQueue(&Q);
//			k = 0;
//		}
//		else
//		{
//			EnQueue(&Q, DeQueue(&Q));
//		}
//	}
//
//	return Q.base[Q.front];
//}



//ѭ������ʵ��
//#include<stdio.h>
//int n;
//typedef struct ListNode
//{
//	int data;
//	struct ListNode* next;
//}LNode;
//LNode* BuyLNode(int x)
//{
//	LNode* new = (LNode*)malloc(sizeof(LNode));
//	new->next = NULL;
//	new->data = x;
//	return new;
//}
//
//int Monkey2()
//{
//	int i = 0;
//
//	LNode* phead = BuyLNode(i);
//	LNode* cur = phead;
//	for (i = 1; i <= n; i++)
//	{
//		cur->next = BuyLNode(i);
//		cur = cur->next;
//	}
//	cur->next= phead->next;//������ӵ�ͷ��
//
//	cur = phead->next;
//	int k =1;//�������Ϊ��������ֻ��ɾ����һ����㣬�����ڴ˽�k��Ϊ1��
//	while (cur->next != cur)
//	{
//		k++;
//		if (k == 3)
//		{
//			//ɾ����һ�����
//			LNode* next = cur->next->next;
//			free(cur->next);
//			cur->next = next;
//
//			cur = cur->next;
//			k = 1;
//		}
//		else
//		{
//			cur = cur->next;
//		}
//	}
//
//	return cur->data;
//
//
//}

//��ͨ����
//������̭������Ԫ�أ����ӣ���Ϊ0
#include<stdio.h>
int n;
int Monkey3()
{
	int* arr = (int*)malloc((n+1)*sizeof(int));
	int i;
	for (i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	int k = 0;
	int count = n;
	while (count > 1)
	{
		for (i = 1; i <= n; i++)
		{
			if (arr[i] == 0)
			{
				continue;
			}
			k++;
			
			if (k == 3)
			{
				arr[i] = 0;
				count--;
				k = 0;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (arr[i] != 0)
			return arr[i];
	}

}
int main(void)
{

	scanf("%d", &n);
	//n++;//���ѭ������Ҫ��һ��Ԫ�ؿռ�����ж��Ƿ������������++,�Ա�������ٿռ��Q.front��Q.rear��ѭ���ƶ�
	//int ret=Monkey1();
	///int ret = Monkey2();
	int ret = Monkey3();

	printf("%d\n", ret);
	return 0;
}

