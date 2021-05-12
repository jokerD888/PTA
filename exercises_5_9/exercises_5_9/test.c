#define _CRT_SECURE_NO_WARNINGS 1

//7 - 42 龟兔赛跑
//#include<stdio.h>
//int main(void)
//{
//	int t,t0,t1=0;
//	int rab = 0, tor = 0;
//	scanf("%d", &t);
//	t0 = t % 10;
//	t -= t0;
//	while(t>0)
//	{
//		if (rab > tor)
//		{
//			if (t >= 30)
//			{
//				t -= 30;
//				tor += 90;
//			}
//			else
//			{
//				t1 = 30 - t;
//				tor += (t * 3);
//				t = 0;
//			}
//		}
//		else
//		{
//			t -= 10;
//			rab += 90;
//			tor += 30;
//		}
//
//	}
//	//在最后不到10分钟内，兔子比乌龟快，且之前的休息时间都为30分钟
//	if (rab > tor && t1 == 0)
//		t1 = 30;
//	if (t1 < t0)
//		rab = rab + (t0 - t1) * 9;
//	tor += (t0 * 3);
//	if (rab > tor)
//		printf("^_^ %d\n", rab);
//	else if (rab < tor)
//		printf("@_@ %d\n", tor);
//	else
//		printf("-_- %d\n",tor);
//	return 0;
//}

//**
//#include<stdio.h>
//int main()
//{
//    int T;
//    int t = 0;//时间
//    int a = 0, b = 0;//a为乌龟，b为兔子
//    int btime = 0;//兔子的时间
//    int rest = 0;//兔子是否在休息的状态
//    scanf("%d", &T);
//    while (t != T)
//    {
//        a += 3;//乌龟跑
//        if (!rest)//如果兔子不在休息
//        {
//            b += 9;//兔子跑
//            btime++;//兔子时间+
//        }
//        t++;//时间+
//        if (t % 10 == 0 && !rest)
//        {
//            if (b > a)//如果兔子在乌龟前面
//            {
//                rest = 1;//休息
//                btime += 30;//兔子时间+30
//            }
//        }
//        if (t == btime)//时间赶上兔子时间
//        {
//            rest = 0;//兔子退出休息
//        }
//    }
//    if (a > b)
//    {
//        printf("@_@ %d", a);
//    }
//    if (a < b)
//    {
//        printf("^_^ %d", b);
//    }
//    if (a == b)
//    {
//        printf("-_- %d", a);
//    }
//    return 0;
//}



//7 - 43 币值转换
// 
// 最初想法，极为复杂，可读性极低，逻辑混乱
//#include<stdio.h>
//int main(void)
//{
//	int n = 0,i=0,num=0;
//	int start = 0,end;
//	int arr[10];
//	char str[50] = { 0 };
//	scanf("%d", &n);
//	if (n == 0)
//	{
//		printf("a\n");
//		return 0;
//	}
//	while (n)
//	{
//		if (i == 1 || i==9)
//		{
//			str[i] = 'S';
//			i++;
//		}
//		else if (i == 3 || i==11)
//		{
//			str[i] = 'B';
//			i++;
//		}
//		else if (i == 5 || i==13)
//		{
//			str[i] = 'Q';
//			i++;
//		}
//		else if (i == 7)
//		{
//			str[i] = 'W';
//			i++;
//		}
//		else if (i == 15)
//		{
//			str[i] = 'Y';
//			i++;
//		}
//		else
//		{
//			str[i] = n % 10 + 'a';
//			i++;
//			n /= 10;
//		}
//	}
//	end = --i;
//	
//	while (start <= end)
//	{
//		char tmp = str[start];
//		str[start] = str[end];
//		str[end] = tmp;
//		start++;
//		end--;
//	}
//	int len = strlen(str);
//	//printf("%s\n", str);
//	int pre=0, next=0,j,k;
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] == 'S' || str[i] == 'B' || str[i] == 'Q' || str[i] == 'Y')
//			;
//		else if (str[i] == 'a')
//		{
//			if (pre == 0)
//				pre = i;
//			else
//			{
//				next = i;
//				for (j = next + 1,k=pre+1; j <= len; j++,k++)
//				{
//					str[k] = str[j];
//				}
//				len = len - (next - pre);
//				i = pre;
//				pre=next=0;
//			}
//		}
//		else
//		{
//			pre = next = 0;
//		}
//	}
//	if (str[len - 1] == 'a')
//	{
//		str[len - 1] = '\0';
//		len--;
//	}
//	//printf("%s\n", str);
//
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] == 'a' && (str[i + 1] == 'S' || str[i + 1] == 'B'))
//		{
//			
//			for (j=i+1; j < len; j++)
//			{
//				str[j] = str[j+1];
//			}
//			len--;
//		}
//	}
//
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] == 'a' && (str[i + 1] == 'W'))
//		{
//			for (j = i; j < len; j++)
//			{
//				str[j] = str[j + 1];
//			}
//		}
//	}
//	printf("%s\n", str);
//	
//	return 0;
//}


//改进，以万单位分开成两部分,并且把“大写”用数组表示
#include<stdio.h>
int main(void)
{
	char num[] = { 'a','b','c','d','e','f','g','h','i','j' };
	char unit[] = { 0,0,'S','B','Q','W','S','B','Q','Y' };
	char result[17];
	int n, k = 0, bitnum = 0, cur = 0, pre = 0;

	scanf("%d", &n);

	if (n == 0)
	{
		printf("a\n");
		return 0;
	}
	while (n)
	{
		cur = n % 10;
		n /= 10;
		bitnum++;

		if (cur)//当前为不为0
		{
			//当前位不为个位，存入单位
			if (bitnum > 1)
			{
				result[k++] = unit[bitnum];
			}

			result[k++] = num[cur];
		}
		else//为0
		{
			//存入“万”
			if (bitnum == 5)
			{
				result[k++] = unit[bitnum];
			}

			if (pre != 0)//此位前面一位不为0
			{
				result[k++] = 'a';
			}
		}
		pre = cur;
	}

	for (int i = k - 1; i >= 0; i--)
	{
		printf("%c", result[i]);
	}
	return 0;
}