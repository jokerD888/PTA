//7-5 ��ǰ׺���ʽ��ֵ 
//#include<math.h>
//#include<sstream>
//#include<iostream>
//using namespace std;
//stringstream ss;//string �������ݣ���������һ��һ���ո�Ķ�ȡ 
//int flag;//�����־ 
//double f()//���㺯�� 
//{
//    char c[9];//���ݲ��ᳬ����λ�� 
//    if (!(ss >> c))
//		flag = 1;  //������ȥ˵�����ݲ��������� 
//    if (c[1] == '\0'){//ֻ��һλ�����ܻ�������� 
//        double numb1, numb2;
//        switch (c[0])
//        {
//        case '+':return f() + f(); break;
//        case '-':return f() - f(); break;
//        case '*':return f()*f(); break;
//        case '/'://����Ҫ���������� ��׼ȷ�Ĵ��� 
//            numb1 = f(); numb2 = f();
//            if (fabs(numb2-0.0)<0.0000001){//���ȴ��� 
//                flag = 1;
//                return 0.0;
//            }
//            else return numb1 / numb2; break;
//        }
//        //���Ƿ��������Ļ���Ӱ�졣�����return 
//    }
//    return atof(c);//������������ 
//}
//int main()
//{
//    string s;
//    flag = 0;
//    getline(cin, s);//���ж��� 
//    ss << s;//��������� 
//    double n = f();//������ 
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
//		double x=0;	//ȡ�������� 
//		int w=1;	//��λ���� 
//		while(a[i]!=' '){
//			if(a[i]=='-'){	//���� 
//				x=-x;
//			}else if(a[i]=='.'){	//С�� 
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


//7-6 Ѱ�Ҵ���
//#include<iostream> 
//using namespace std;
//#include<vector>
//#include<algorithm>
//int main(void) {
//	int N, M;
//	cin >> N >> M;
//	if (N < M)		//NС��M�Ļ�����ǰM����Ǯ��ΪN������Ǯ
//		M = N;
//	vector<int> arr;
//	for (int i = 0; i < N; i++) {
//		int tmp;
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//
//	sort(arr.begin(), arr.end(), greater<int>());	//���Ӵ�С����
//	for (int i = 0; i < M-1; i++) {
//		cout<< arr[i] << ' ';
//	}
//	cout << arr[M - 1];		//��β�����п���
//	return 0;
//}


//7 - 7 ���ݺ���������������������
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
//	int root = pos[posR];//�Ӻ������Ҹ�
//	int i = index[root];	//���������е�λ��
//	int cnt = i - inL;	//�������ڵ���
//	cout << ' ' << root;
//	//�ݹ�����
//	getPre(pos, in, posL,posL+cnt-1 , inL,i-1  );	
//	//�ݹ�����
//	getPre(pos, in, posL+cnt, posR - 1, i + 1, inR);//��Ҫ����Ϊ�˴���posL+cnt������i�������Ϊ��������������һ������ͺ������
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

