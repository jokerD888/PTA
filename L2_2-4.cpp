#include<bits/stdc++.h>

using namespace std;
//7-2 Ӣ�ĵ�������
//
//class Mycomp{
//public:
//	bool operator()(const string& val1,const string& val2)
//	{
//		return val1.size()<val2.size();
//	}
//};
//int main()
//{
//	
//
//	vector<string> ans;
//	string tmp;
//	while(tmp!="#"){
//		cin>>tmp;
//		ans.push_back(tmp);
//	}
//	ans.pop_back(); 
//	
//	stable_sort(ans.begin(),ans.end(),Mycomp());
//	for(auto i:ans)
//	{
//		cout<<i<<" ";
//	}
//	return 0;
//}

//7-3 ����ҵ����м�ģ�� 
//#include<iostream>
//using namespace std;
//#include<queue> 
//int main(void)
//{
//	int n;
//	queue<int> A,B;
//	cin>>n;
//	int cnt=n;
//	while(n--){
//		int tmp;
//		cin>>tmp;
//		if(tmp%2){
//			A.push(tmp);
//		}else {
//			B.push(tmp);
//		}
//	}
//	int time=0;
//	while(!A.empty() && !B.empty()){
//		if(!A.empty()){
//			cout<<A.front();
//			if(cnt!=1)
//				cout<<' ';
//			A.pop();
//			cnt--;
//		}
//		if(!A.empty()){
//			cout<<A.front();
//			if(cnt!=1)
//				cout<<' ';
//			A.pop();
//			cnt--;
//		}
//		if(!B.empty()){
//			cout<<B.front();
//			if(cnt!=1)
//				cout<<' ';
//			B.pop();
//			cnt--;
//		}
//	}
//	while(!B.empty()){
//		cout<<B.front();
//		if(cnt!=1)
//				cout<<' ';
//		B.pop();
//		cnt--;
//	}
//	while(!A.empty()){
//		cout<<A.front();
//		if(cnt!=1)
//				cout<<' ';
//		A.pop();
//		cnt--;
//	}
//	return 0;
// } 


//7-4 ���ʽת��

#include <bits/stdc++.h>
using namespace std;
void to_deal(string str){
    stack<char> stk;
    //�������ȼ�
    map<char,int> m;
    m['+'] = m['-'] = 1;m['*'] = m['/'] = 2;m['('] = m[')'] = 3;
    
    int index = 0;
    bool flag = true;//�ж��Ƿ��ǵ�һ���
    while(index < str.size()){
        //�ж��Ƿ��ǲ�����
        //����Ŀ����������ִ���+-�ŵ��������Ҫ�ж�+-�������û��ǼӼ��� 
        //&& ��ߵ�������Ϊ���ж������ţ����׸��ַ��ͣ����ұߵĵ�һ�� ��λ�òŻ��������� 
        if((index < 1 || str[index - 1] == '(') && 
		(str[index] == '+' || str[index] == '-')  || isdigit(str[index])){
            if(flag)  
				flag = false;
            else
				 printf(" ");
            if(str[index] != '+') 
				printf("%c", str[index]);
			//��������С���㣬����ȫ��������� 
            while(str[index + 1] == '.' || isdigit(str[index + 1]))
                printf("%c", str[++index]);
            index++;
        }else{
            //�����������,�Ƚ����ȼ�,�������ȼ����ڵ����Լ��ġ�
            if(str[index] == '(') 
				stk.push(str[index]);
            else if(str[index] == ')'){	
				//������֮ǰ�Ĳ����� 
                while(!stk.empty() && stk.top() != '('){
                    printf(" %c", stk.top());
                    stk.pop();
                }
                stk.pop();
            }else{
            	//�������ȼ����ڵ����Լ��ġ�
                while(!stk.empty() && stk.top() != '(' && m[stk.top()] >= m[str[index]]){
                    printf(" %c", stk.top());
                    stk.pop();
                }
                stk.push(str[index]);
            }
            index++;
        }
    }
    while(!stk.empty()){
        printf(" %c", stk.top());
        stk.pop();
    }
}
int main()
{
    string str;
    cin>>str;
    to_deal(str);
    return 0;
}


