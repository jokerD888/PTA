#define _CRT_SECURE_NO_WARNINGS 1

//7 - 42 ��������
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
//	//����󲻵�10�����ڣ����ӱ��ڹ�죬��֮ǰ����Ϣʱ�䶼Ϊ30����
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
//    int t = 0;//ʱ��
//    int a = 0, b = 0;//aΪ�ڹ꣬bΪ����
//    int btime = 0;//���ӵ�ʱ��
//    int rest = 0;//�����Ƿ�����Ϣ��״̬
//    scanf("%d", &T);
//    while (t != T)
//    {
//        a += 3;//�ڹ���
//        if (!rest)//������Ӳ�����Ϣ
//        {
//            b += 9;//������
//            btime++;//����ʱ��+
//        }
//        t++;//ʱ��+
//        if (t % 10 == 0 && !rest)
//        {
//            if (b > a)//����������ڹ�ǰ��
//            {
//                rest = 1;//��Ϣ
//                btime += 30;//����ʱ��+30
//            }
//        }
//        if (t == btime)//ʱ���������ʱ��
//        {
//            rest = 0;//�����˳���Ϣ
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



//7 - 43 ��ֵת��
// 
// ����뷨����Ϊ���ӣ��ɶ��Լ��ͣ��߼�����
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


//�Ľ�������λ�ֿ���������,���Ұѡ���д���������ʾ
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

		if (cur)//��ǰΪ��Ϊ0
		{
			//��ǰλ��Ϊ��λ�����뵥λ
			if (bitnum > 1)
			{
				result[k++] = unit[bitnum];
			}

			result[k++] = num[cur];
		}
		else//Ϊ0
		{
			//���롰��
			if (bitnum == 5)
			{
				result[k++] = unit[bitnum];
			}

			if (pre != 0)//��λǰ��һλ��Ϊ0
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