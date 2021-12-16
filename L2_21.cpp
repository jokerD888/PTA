//7-21 ���޿�ħ 
//#include<iostream>
//using namespace std;
//#include<set>
//#include<vector>
//#include<algorithm>
//struct People {
//	string name;		//����
//	int sum=0;			//��ǩ����
//	set<int> f;			//��ǩ��ţ��Զ��޳��ظ���ͬ��ǩ
//};
//
//
//bool myCompare(const People& a,const People& b) {
//	if (a.f.size() != b.f.size()) {
//		return a.f.size() > b.f.size();
//	} else {
//		return a.sum < b.sum;
//	}
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<People> a(105);
//	
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a[i].name;
//		int t, k;
//		cin >> k;
//		a[i].sum = k;
//		for (int j = 0; j < k; j++)
//		{
//			cin >> t;
//			a[i].f.insert(t);
//		}
//	}
//
//	sort(a.begin(), a.begin()+N, myCompare);
//	int i = 0;
//	for(i=0;i<N;){
//		cout << a[i].name;
//		if (++i >= 3) {
//			break;
//		} else {
//			cout << ' ';
//		}
//	}
//	for (int j = i; j < 3; ++j) {
//		cout << '-';
//		if (j != 2) {
//			cout << ' ';
//		}
//	}
//	return 0;
//}
//

//��
#include<iostream>
using namespace std;
#include<set>
#include<vector>
#include<algorithm>
struct People {
	string name;		//����
	int sum = 0;			//��ǩ����
	set<int> f;			//��ǩ��ţ��Զ��޳��ظ���ͬ��ǩ
};


bool myCompare(const People& a, const People& b) {
	if (a.f.size() != b.f.size()) {
		return a.f.size() > b.f.size();
	} else {
		return a.sum < b.sum;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<People> a;

	//������Ϣ
	for (int i = 0; i < N; ++i) {
		People tmp;
		cin >> tmp.name;
		int k,t;
		cin >> k;
		tmp.sum = k;
		for (int j = 0; j < k; ++j) {
			cin >> t;
			tmp.f.insert(t);
		}
		a.push_back(tmp);
	}

	sort(a.begin(), a.end(), myCompare);
	int i = 0;
	for (i = 0; i < N;) {
		cout << a[i].name;
		if (++i >= 3) {
			break;
		} else {
			cout << ' ';
		}
	}
	for (int j = i; j < 3; ++j) {
		cout << '-';
		if (j != 2) {
			cout << ' ';
		}
	}
	return 0;
}

