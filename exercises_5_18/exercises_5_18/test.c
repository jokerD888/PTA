#define _CRT_SECURE_NO_WARNINGS 1
//7 - 46 ɾ���ַ����е��Ӵ�
//���������ͨ���˲��ֲ��Ե㣬��������ַ���������
// ͨ��һ�ٲ��ң������ǵ�24�е�strcpy�����е�pos+len����ַ���������£����ܳ���������Խ�����⣬dest��source��ָ�ڴ������ص�����
//���ǣ������Խ������󣬻��ǲ���ͨ�����ԣ�����һ�ٲ��ң�����������Ҳ����õ�fgets����
// ����Ϊ���ojϵͳ�ᾯ��gets��������ȫ�����Ծʹ˿�ʼ��fgets()���gets()ʹ�ã�
// ͨ�������Եĵ����ڣ��ҽ�fgets�����еĵڶ��������ַ��ĸ������ó���81��������80���ַ�������ʵ�����Ҫ�����ַ��ռ����'\n'��'\0',������СӦ����Ϊ82
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
//���Ǿ����޸Ĵ��룬������ʵ�����ַ���ǰ�ƣ�����Խ����ʺ�
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char s1[100] = { 0 };
//	char s2[100] = { 0 };
//	fgets(s1,82,stdin);//82
//	s1[strlen(s1) - 1] = '\0';//ȥ'\n'
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
//		//������ط���strcpy(pos, pos + len);
//		//��һ��
//		/*for (int i = 0; *(pos + i); i++)
//		{
//			*(pos + i) = *(pos + len + i);
//		}*/
//		//���������������ڴ��ص���
//		strcpy(tmp, pos + len);
//		strcpy(pos, tmp);
//	}
//	printf("%s", s1);
//
//	return 0;
//}

//��Σ��ڷ�������Ĺ����У���������������Ҳ���Ա�������Խ��
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char s1[100] = { 0 };
//	char s2[100] = { 0 };
//	fgets(s1, 82, stdin);//82
//	s1[strlen(s1) - 1] = '\0';//ȥ'\n'
//
//	fgets(s2, 82, stdin);
//	s2[strlen(s2) - 1] = '\0';
//
//	char tmp[100];//��ʱ����
//	char* pos;
//	while (pos = strstr(s1, s2))
//	{
//		strcpy(tmp, pos + strlen(s2));//�ӱ�Ҫɾ�����ִ���ʼ�����ַ�����tmp��
//		*pos = '\0';//��pos��ǰ��ָ�ַ���Ϊ'\0'��
//		strcat(s1, tmp);//��tmp�������s1����ֹ��֮��,�൱�����ϵķ���
//	}
//	
//	printf("%s", s1);
//	return 0;
//}


//7 - 47 �ַ�����ð������
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