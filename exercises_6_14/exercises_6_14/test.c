#define _CRT_SECURE_NO_WARNINGS 1

//7 - 60 Êä³öGPLT
//#include<stdio.h>
//int main(void)
//{
//	int i = 0;
//	int gnum, pnum, lnum, tnum;
//	gnum = pnum = lnum = tnum = 0;
//	char str[10001];
//	scanf("%s", str);
//	while (str[i] != '\0')
//	{
//		if (str[i] == 'g' || str[i] == 'G')
//			gnum++;
//		else if (str[i] == 'p' || str[i] == 'P')
//			pnum++;
//		else if (str[i] == 'l' || str[i] == 'L')
//			lnum++;
//		else if (str[i] == 't' || str[i] == 'T')
//			tnum++;
//
//		i++;
//	}
//
//	while (gnum>0 || pnum>0 || lnum>0 || tnum>0)
//	{
//		if (gnum-- > 0)
//			printf("G");
//		if (pnum-- > 0)
//			printf("P");
//		if (lnum-- > 0)
//			printf("L");
//		if (tnum-- > 0)
//			printf("T");
//	}
//	return 0;
//}


//7 - 61 ³ö×â
//#include<stdio.h>
//int main(void)
//{
//	char num[12];
//	scanf("%s", num);
//	int count = 0;
//	int number[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 11; i++)
//	{
//		number[num[i] - '0'] = 1;
//	}
//
//	for (i = 0; i < 11; i++)
//	{
//		if (number[i] == 1)
//			count++;
//	}
//
//	int* arr = (int*)malloc(sizeof(int) * count);
//	int j = 0;
//	for (i = 10; i >=0; i--)
//	{
//		if (number[i] == 1)
//			arr[j++] = i;
//	}
//
//	int index[11] = { 0 };
//	for (i = 0; i < 11; i++)
//	{
//		for (j = 0; j < count; j++)
//		{
//			if (num[i] - '0' == arr[j])
//			{
//				index[i] = j;
//				break;
//			}
//		}
//	}
//	printf("int[] arr = new int[]{");
//	for (i = 0; i < count; i++)
//	{
//		if(i==count-1)
//			printf("%d};\n", arr[i]);
//		else
//		   printf("%d,",arr[i]);
//	}
//	printf("int[] index = new int[]{");
//	for (i = 0; i < 11; i++)
//	{
//		if (i == 10)
//			printf("%d};\n", index[i]);
//		else
//			printf("%d,", index[i]);
//	}
//
//	return 0;
//}



//7 - 62 Left - pad
#include<stdio.h>
#include<string.h>
int main(void)
{
	int n;
	char c;
	scanf("%d %c\n", &n, &c);
	char str[100000];
	gets(str);
	int len = strlen(str);
	if (n <= len)
		//printf("%s", str + len - n);
		puts(str + len - n);
	else
	{
		memmove(str + n - len, str, (len + 1) * sizeof(char));
		int i = 0;
		for (i = 0; i < n - len; i++)
		{
			str[i] = c;
		}
		puts(str);
	}
	
	return 0;
}