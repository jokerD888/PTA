#define _CRT_SECURE_NO_WARNINGS 1
//7 - 52 ץ����~���˻���׬�ˣ�
//��������о�Щ���ӣ���������ĳһЩ��ϵ��������һ���
//�磺����if(happy)�����Ҫhappy--,����dead��unhappy����״̬Ҳ��һ����
//������Щ���printf("D"); dead = 2; money += 7; cheese = 0;����������һ���ִ�е�
//printf("!"); money -= 3; cheese = 0; happy = 2;Ҳ�����
//#include<stdio.h>
//int main(void)
//{
//	char day[72];
//	scanf("%s", day);
//	fgets(day, 72, stdin);
//	int money = 0;
//	int unhappy = 0;
//	int happy=0;
//	int dead = 0;
//	int cheese = 0;
//	int i = 0;
//	while (day[i] != '$')
//	{
//			switch (day[i])
//			{
//			case 'X':
//				if (happy)
//				{
//					printf("U");
//					--happy;
//				}
//				else if (unhappy|| dead)
//				{
//					if (unhappy)
//						unhappy = 0;
//					else dead--;
//					printf("-");
//				}
//				else
//				{
//					printf("U");
//					unhappy = 1;
//				}
//				break;
//			case 'T':
//				if (happy)
//				{
//					happy--;
//					printf("D");
//					dead = 2;
//					money += 7;
//					cheese = 0;
//				}
//				else if (unhappy || dead)
//				{
//					if (unhappy)
//						unhappy = 0;
//					else dead--;
//					printf("-");
//				}
//				else 
//				{
//					printf("D");
//					dead = 2;
//					money += 7;
//					cheese = 0;
//				}
//				break;
//			case 'C':
//			
//				if (happy)
//				{
//					printf("!");
//					money -= 3;
//					cheese = 0;
//					happy = 2;
//
//				}
//				else if (unhappy || dead)
//				{
//					if (unhappy)
//						unhappy = 0;
//					else dead--;
//					printf("-");
//				}
//				else
//				{
//					printf("!");
//					money -= 3;
//					cheese = 0;
//					happy = 2;
//				}
//			
//				break;
//			}
//		
//		i++;
//	}
//	printf("\n%d", money);
//
//	return 0;
//}



#include<stdio.h>
int money = 0;
void search(char a, int* p) {
	if (a == 'X') {
		if (*p == 2) *p = 1;
		else *p = 0;
		printf("U");
	}
	else if (a == 'T') {
		if (*p == 2) *p = 1;
		else *p = 3;
		printf("D");
		money = money + 7;
	}
	else if (a == 'C') {
		*p = 2;
		printf("!");
		money = money - 3;
	}
}
int main(void) {
	char s[70];
	scanf("%s", s);
	int i = 0, state = 1;//state��ֵ: 1=������ 0=�������� 2=������ 3=���첻�� 
	while (s[i] != '$') {
		if (state == 0) {
			//��������
			printf("-");
			state = 1;
		}
		else if (state == 1) {
			//������
			sea7rch(s[i], &state);
		}
		else if (state == 2) {
			//�˷���
			search(s[i], &state);
		}
		else if (state == 3) {
			//������
			printf("-");
			state = 0;
		}
		i++;
	}
	printf("\n%d", money);
}
