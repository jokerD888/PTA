//7-5 求前缀表达式的值 
//#include<math.h>
//#include<sstream>
//#include<iostream>
//using namespace std;
//stringstream ss;//string 流存数据，这样可以一个一个空格的读取 
//int flag;//错误标志 
//double f()//运算函数 
//{
//    char c[9];//数据不会超过九位数 
//    if (!(ss >> c))
//		flag = 1;  //流不进去说明数据不够。错误 
//    if (c[1] == '\0'){//只有一位，可能会是运算符 
//        double numb1, numb2;
//        switch (c[0])
//        {
//        case '+':return f() + f(); break;
//        case '-':return f() - f(); break;
//        case '*':return f()*f(); break;
//        case '/'://除号要避免非零错误 和准确的错误 
//            numb1 = f(); numb2 = f();
//            if (fabs(numb2-0.0)<0.0000001){//精度错误 
//                flag = 1;
//                return 0.0;
//            }
//            else return numb1 / numb2; break;
//        }
//        //不是符号是数的话不影响。后面会return 
//    }
//    return atof(c);//把运算数返回 
//}
//int main()
//{
//    string s;
//    flag = 0;
//    getline(cin, s);//整行读入 
//    ss << s;//存进流里面 
//    double n = f();//算出结果 
//    if (flag)
//		cout << "ERROR" << endl;
//    else 
//		printf("%.1lf\n", n);
//}


//#include<iostream>
//using namespace std;
//#include<stack>
//int main(void)
//{
//	string a;
//	getline(cin,a);
//	stack<char> st;
//	int a=0;
//	int i=a.size();
//
//	while(--i){
//		double x=0;	//取出的数子 
//		int w=1;	//几位数字 
//		while(a[i]!=' '){
//			if(a[i]=='-'){	//负数 
//				x=-x;
//			}else if(a[i]=='.'){	//小数 
//				
//			}
//			
//			x=x+a[i]*w;
//			w*=10;
//		}
//		
//		if(a[i]==' ')	continue;
//		if(isdigit(a[i])){
//			st.push(a[i]);
//		}else if()
//		
//	}
//	
//	
//	return 0;
//}
// 


//7-6 寻找大富翁
//#include<iostream> 
//using namespace std;
//#include<vector>
//#include<algorithm>
//int main(void) {
//	int N, M;
//	cin >> N >> M;
//	if (N < M)		//N小于M的话，即前M人有钱即为N人最有钱
//		M = N;
//	vector<int> arr;
//	for (int i = 0; i < N; i++) {
//		int tmp;
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//
//	sort(arr.begin(), arr.end(), greater<int>());	//按从大到小排序
//	for (int i = 0; i < M-1; i++) {
//		cout<< arr[i] << ' ';
//	}
//	cout << arr[M - 1];		//结尾不能有空行
//	return 0;
//}


//7 - 7 根据后序和中序遍历输出先序遍历
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<unordered_map>
//unordered_map<int, int> index;
//
//void getPre(vector<int>& pos, vector<int>& in, int posL,int posR,int inL,int inR) {
//	if (posL>posR)
//		return;
//
//	int root = pos[posR];//从后序中找根
//	int i = index[root];	//根在中序中的位置
//	int cnt = i - inL;	//左子树节点数
//	cout << ' ' << root;
//	//递归左树
//	getPre(pos, in, posL,posL+cnt-1 , inL,i-1  );	
//	//递归右树
//	getPre(pos, in, posL+cnt, posR - 1, i + 1, inR);//不要误以为此处的posL+cnt可以用i替代，因为右树并不像左树一样中序和后序对齐
//
//	
//}
//int main()
//{
//	int N;
//	cin >> N;
//	vector<int> pre, in, pos;
//	for (int i = 0; i < N; i++) {
//		int tmp;
//		cin >> tmp;
//		pos.push_back(tmp);
//	}
//	for (int i = 0; i < N; i++) {
//		int tmp;
//		cin >> tmp;
//		in.push_back(tmp);
//		index[tmp] = i;
//
//	}
//	cout << "Preorder:";
//	getPre(pos, in, 0, N - 1, 0, N - 1);;
//
//	return 0;
//}

