#define _CRT_SECURE_NO_WARNINGS 1
//7 - 46 删除字符串中的子串
//最初做法，通过了部分测试点，卡在了最长字符串问题上
// 通过一顿查找，发现是第24行的strcpy函数中的pos+len在最长字符串的情况下，可能出现了数组越界问题，dest和source所指内存区域重叠所致
//但是，解决了越界问题后，还是不能通过测试，又是一顿查找，发现了这个我不常用的fgets函数
// （因为许多oj系统会警告gets函数不安全，所以就此开始用fgets()替代gets()使用）
// 通不过测试的点在于，我将fgets函数中的第二个读入字符的个数设置成了81（最多读入80个字符），但实际最后还要两个字符空间读入'\n'和'\0',所以最小应设置为82
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char s1[100] = { 0 };
//	char s2[100] = { 0 };
//	fgets(s1,81,stdin);
//	s1[strlen(s1) - 1] = '\0';
//	
//	fgets(s2,81,stdin);
//	s2[strlen(s2) - 1] = '\0';
//
//	int len = strlen(s2);
//	char* pos = strstr(s1, s2);
//	while (pos )
//	{
//		strcpy(pos, pos + len);
//		pos = strstr(s1, s2);
//	}
//	printf("%s", s1);
//
//	return 0;
//}
// 
//于是精简修改代码，并自行实现了字符串前移，避免越界访问后：
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char s1[100] = { 0 };
//	char s2[100] = { 0 };
//	fgets(s1,82,stdin);//82
//	s1[strlen(s1) - 1] = '\0';//去'\n'
//		
//	fgets(s2,82,stdin);
//	s2[strlen(s2) - 1] = '\0';
//
//	int len = strlen(s2);
//	char* pos; 
//	char tmp[100] = { 0 };
//	while (pos = strstr(s1, s2))
//	{
//
//		//（错误地方）strcpy(pos, pos + len);
//		//法一：
//		/*for (int i = 0; *(pos + i); i++)
//		{
//			*(pos + i) = *(pos + len + i);
//		}*/
//		//法二：（避免了内存重叠）
//		strcpy(tmp, pos + len);
//		strcpy(pos, tmp);
//	}
//	printf("%s", s1);
//
//	return 0;
//}

//其次，在发现问题的过程中，发现了以下做法也可以避免数组越界
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char s1[100] = { 0 };
//	char s2[100] = { 0 };
//	fgets(s1, 82, stdin);//82
//	s1[strlen(s1) - 1] = '\0';//去'\n'
//
//	fgets(s2, 82, stdin);
//	s2[strlen(s2) - 1] = '\0';
//
//	char tmp[100];//临时数组
//	char* pos;
//	while (pos = strstr(s1, s2))
//	{
//		strcpy(tmp, pos + strlen(s2));//从被要删除的字串开始复制字符串到tmp中
//		*pos = '\0';//把pos当前所指字符置为'\0'。
//		strcat(s1, tmp);//将tmp数组接在s1的终止符之后,相当于其上的法二
//	}
//	
//	printf("%s", s1);
//	return 0;
//}


//7 - 47 字符串的冒泡排序
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[100][12] = { 0 };
	char tmp[12];
	int n, k,i;
	scanf("%d%d", &n, &k);
	getchar();
	for (i = 0; i < n; i++)
	{
		fgets(str[i], 12, stdin);

	}

	for (i = 0; i <k; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (strcmp(str[j], str[j + 1])>0)
			{
				strncpy(tmp,str[j],12);
				strncpy(str[j], str[j+1], 12);
				strncpy(str[j+1],tmp, 12);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		fputs(str[i], stdout);
	}
	return 0;
}