#define _CRT_SECURE_NO_WARNINGS 1
//7 - 48 �ַ���ѭ������
//#include<stdio.h>
//void reverse(char* s, int left, int right)
//{
//	while (left < right)
//	{
//		char tmp = s[left];
//		s[left] = s[right];
//		s[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main(void)
//{
//	char s[102];
//	fgets(s, 102, stdin);
//	int len = strlen(s);
//	s[len - 1] = '\0';
//	len--;
//	int k,i;
//	scanf("%d", &k);
//	k %= len;
//
//	reverse(s, 0, k-1);
//	reverse(s, k, len-1);
//	reverse(s, 0, len-1);
//
//	fputs(s, stdout);
//	return 0;
//}


////7 - 49 ˵���� - ��ǿ��
//��ʽ�洢ջ��ʾ��
//#include<stdio.h>
//#include<stdbool.h>
//#include<assert.h>
//typedef char STDataType;
//typedef struct StackNode
//{
//	struct QueueNode* next;
//	STDataType* data;
//}SNode;
//
//typedef struct Stack
//{
//	SNode* head;
//	SNode* tail;
//}ST;
//void StackInit(ST* pq)
//{
//	assert(pq);
//	pq->head = pq->tail = NULL;
//}
//void StackDestory(ST* ps)
//{
//	assert(ps);
//	SNode* cur;
//	while (ps->head != ps->tail)
//	{
//		SNode* cur = ps->head;
//		ps->head = ps->head->next;
//		free(cur);
//	}
//}
//
////��ջ��ջ
//void StackPush(ST* ps, STDataType* x)
//{
//	assert(ps);
//	int len = strlen(x);
//	SNode* newnode = malloc(sizeof(SNode));
//	if (newnode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	char* tmp = malloc(sizeof(char) * len+1);
//	strcpy(tmp, x);
//	//*(tmp + len) = '\0';
//	if (tmp)
//	{
//		newnode->data = tmp;
//	}
//
//	newnode->next = ps->head;
//	ps->head = newnode;
//}
//void StackPop(ST* ps)
//{
//	assert(ps);
//	SNode* cur = ps->head;
//
//	ps->head = ps->head->next;
//	free(cur);
//}
////ȡջ��Ԫ��
//STDataType* StackTop(ST* ps)
//{
//	assert(ps);
//	return ps->head->data;
//}
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->head==ps->tail;//��Ϊ1,����true,��Ϊ0,����false
//}
//
//int main(void)
//{
//	char str[500002];
//	ST s;
//	StackInit(&s);
//	while (scanf("%s", str) != EOF)
//	{
//		StackPush(&s, str);
//	}
//	while (!StackEmpty(&s))
//	{
//		printf("%s", StackTop(&s));
//		StackPop(&s);
//		if (!StackEmpty(&s))
//			printf(" ");
//	}
//
//	return 0;
//}


//��ͨ����
#include<stdio.h>
#include<string.h>
int main(void)
{
	char s[500002];
	fgets(s, 500002, stdin);
	int len = strlen(s);
	s[len - 1] = '\0';
	len--;

	int i, j;
	int word = 0, first = 1;
	for (i = len - 1; i >= 0; i--)
	{
		if (word != 0 && s[	i] == ' ')
		{
			if (first == 1)//first��־���Ƿ��ǵ�һ���ִ�
				first = 0;
			else
				printf(" ");//����ִ�ǰ��ӡ�ո�
			for (j = i + 1; j <= i + word; j++)
			{
				printf("%c", s[j]);
			}
			word = 0;
		}
		else if (s[i] != ' ')
			word++;
	}
	if (word > 0)//�ʼ������ִ���ǰ�����޿ո��ڴ����
	{
		if(first == 0)
			printf(" ");
		for (j = 0; j <= word - 1; j++)
			printf("%c", s[j]);
	}

	return 0;
}




