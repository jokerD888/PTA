#define _CRT_SECURE_NO_WARNINGS 1


//7 - 53 �зֱ��ʽ����д��tokenizer��
//#include<stdio.h>
//int main(void)
//{
//	char str[100];
//	fgets(str, 100, stdin);
//	str[strlen(str) - 1] = '\0';
//	int i = 0,j=0,k=0;
//	printf("%c", str[i++]);
//	//32*((2-2)+5)/(-15)
//	while (str[i])
//	{
//		if (str[i] == '*' || str[i] == '/' || str[i]=='+')//�����������ǰ���Ҫ����
//		{
//			printf("\n%c\n", str[i]);
//		}
//		else if (str[i] == '(')//'('�ұ߱ض�Ҫ����
//		{
//			printf("%c\n", str[i]);
//		}
//		else if (str[i] == ')')// ')'��߱ض�Ҫ����
//		{
//			printf("\n%c", str[i]);
//		}
//		else if (str[i] == '-')
//		{
//			if (str[i - 1] >= '0' && str[i - 1] <= '9')//��-ǰ�������֣���-�ض����������ǰ���軻��
//			{
//				printf("\n%c\n", str[i]);
//			}
//			else
//				printf("%c", str[i]);
//		}
//		else 
//			printf("%c", str[i]);//���ù�С���㣬С���㱻�������в�Ӱ��
//		i++;
//
//
//	}
//	return 0;
//}


//7-54 �����ֽ�Ϊ������֮�� 
//��ȱ����㷨��һ�����ߵ���
//(���ڴ����޽Ͽ��е�˼·���״θо����㷨�İ�������
#include<stdio.h>
int cnt = 0;
int n, a[50];
void dfs(int number, int n, int location, int sum) 
{
    if (sum > n) return;
    if (sum == n) 
    {
        printf("%d=", n);
        for (int i = 0; i < location; ++i)
            if (i == 0)
                printf("%d", a[i]);
            else
                printf("+%d", a[i]);
        ++cnt;
        if (cnt % 4 != 0 && number != n)
            printf(";");
        if (cnt % 4 == 0 && cnt != 0)
            printf("\n");
    }
    for (int i = number; i <= n; ++i) 
    {
        a[location] = i;
        dfs(i, n, location + 1, sum + i);
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1, n, 0, 0);
}