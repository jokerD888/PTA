#define _CRT_SECURE_NO_WARNINGS 1


//7 - 53 切分表达式——写个tokenizer吧
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
//		if (str[i] == '*' || str[i] == '/' || str[i]=='+')//这三种运算符前后必要换行
//		{
//			printf("\n%c\n", str[i]);
//		}
//		else if (str[i] == '(')//'('右边必定要换行
//		{
//			printf("%c\n", str[i]);
//		}
//		else if (str[i] == ')')// ')'左边必定要换行
//		{
//			printf("\n%c", str[i]);
//		}
//		else if (str[i] == '-')
//		{
//			if (str[i - 1] >= '0' && str[i - 1] <= '9')//若-前面是数字，则-必定是运算符，前后需换行
//			{
//				printf("\n%c\n", str[i]);
//			}
//			else
//				printf("%c", str[i]);
//		}
//		else 
//			printf("%c", str[i]);//不用管小数点，小数点被数字所夹不影响
//		i++;
//
//
//	}
//	return 0;
//}


//7-54 整数分解为若干项之和 
//深度遍历算法，一条道走到黑
//(对于此题无较可行的思路，首次感觉到算法的奥妙）妙啊！！
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