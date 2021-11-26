#include<bits/stdc++.h>

using namespace std;
//7-2 英文单词排序
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

//7-3 银行业务队列简单模拟 
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


//7-4 表达式转换

#include <bits/stdc++.h>
using namespace std;
void to_deal(string str){
    stack<char> stk;
    //定义优先级
    map<char,int> m;
    m['+'] = m['-'] = 1;m['*'] = m['/'] = 2;m['('] = m[')'] = 3;
    
    int index = 0;
    bool flag = true;//判断是否是第一输出
    while(index < str.size()){
        //判断是否是操作数
        //因题目输入会有数字带有+-号的情况，需要判断+-是正负好还是加减号 
        //&& 左边的条件是为了判断正负号，在首个字符和（的右边的第一个 的位置才会是正负号 
        if((index < 1 || str[index - 1] == '(') && 
		(str[index] == '+' || str[index] == '-')  || isdigit(str[index])){
            if(flag)  
				flag = false;
            else
				 printf(" ");
            if(str[index] != '+') 
				printf("%c", str[index]);
			//数可能有小数点，把数全部部分输出 
            while(str[index + 1] == '.' || isdigit(str[index + 1]))
                printf("%c", str[++index]);
            index++;
        }else{
            //操作符的情况,比较优先级,弹出优先级大于等于自己的。
            if(str[index] == '(') 
				stk.push(str[index]);
            else if(str[index] == ')'){	
				//弹出（之前的操作符 
                while(!stk.empty() && stk.top() != '('){
                    printf(" %c", stk.top());
                    stk.pop();
                }
                stk.pop();
            }else{
            	//弹出优先级大于等于自己的。
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


