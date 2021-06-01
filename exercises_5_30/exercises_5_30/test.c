#define _CRT_SECURE_NO_WARNINGS 1
//7 - 52 抓老鼠啊~亏了还是赚了？
//此题初做感觉些许复杂，但其中有某一些关系是捆绑在一起的
//如：进入if(happy)里面必要happy--,进入dead和unhappy两个状态也是一样，
//还有这些语句printf("D"); dead = 2; money += 7; cheese = 0;都是捆绑在一起的执行的
//printf("!"); money -= 3; cheese = 0; happy = 2;也是如此
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
	int i = 0, state = 1;//state的值: 1=派老鼠 0=不派老鼠 2=两天派 3=两天不派 
	while (s[i] != '$') {
		if (state == 0) {
			//不派老鼠
			printf("-");
			state = 1;
		}
		else if (state == 1) {
			//派老鼠
			sea7rch(s[i], &state);
		}
		else if (state == 2) {
			//兴奋期
			search(s[i], &state);
		}
		else if (state == 3) {
			//伤心期
			printf("-");
			state = 0;
		}
		i++;
	}
	printf("\n%d", money);
}
