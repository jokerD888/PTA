
//7-12 互评成绩
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<set>
//#include<climits>
//int main(void)
//{
//	int N, K, M;
//	cin >> N >> K >> M;
//	multiset<double,greater<double>> ans;
//	for (int i = 0; i < N; ++i) {
//		int mi = INT_MAX, ma = INT_MIN,sum=0;
//		for (int j = 0; j < K; ++j) {
//			int score;
//			cin >> score;
//			sum += score;
//			mi = score < mi ? score : mi;
//			ma = score > ma ? score: ma;
//		}
//		sum -= mi;
//		sum -= ma;
//		ans.insert(sum * 1.0 / (K - 2));
//	}
//	int i = 0;
//	vector<double> ret;
//	for (auto a : ans) {
//		ret.push_back(a);
//		if (++i == M)
//			break;
//	}
//	for (size_t i = ret.size(); i != 1; --i) {
//		printf("%.3lf ", ret[i - 1]);
//	}
//	printf("%.3lf", ret[0]);
//
//	return 0;
//}
//
//或 
//#include<iostream>
//using namespace std;
//#include<vector>
//int main()
//{
//	long long n = 2021041820210418,sum=0;
//
//	vector<long long > pri;
//	int q = sqrt(n);
//	for (int i = 1; i <= q; ++i) {
//		if (n % i == 0) {
//			pri.push_back(i);
//			pri.push_back(n/i);
//		}
//	}
//	if (pri[pri.size() - 1] == pri[pri.size() - 2]) {
//		pri.pop_back();
//	}
//
//	int len = pri.size(),cnt=0;
//	for ( int i = 0; i < len; ++i) {
//		for (int j = 0; j < len; ++j) {
//			if (n % (pri[i] * pri[j]) == 0)
//				++cnt;
//			
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}


//7-13 愿天下有情人都是失散多年的兄妹
//#include<iostream>
//using namespace std;
//const int N = 1e6;	//N是五位数
//struct Node {
//	int dad, mom;	//父母编号
//	char sex;
//	Node() :dad(-1), mom(-1), sex('M') {}	//初始化
//}fam[N];//借助数组下标表示本人的编号
//
//bool Find(int a, int b, int cnt) {
//	if (a == -1 || b == -1) {	//如果无法考证，即可结合
//		return true;
//	}
//	//父母可以考证，且若是同父或同母，那就不行了
//	if ((fam[a].dad != -1 && fam[a].dad == fam[b].dad) || (fam[a].mom != -1 && fam[a].mom == fam[b].mom) ){
//		return false;
//	}
//	++cnt;	//代数++
//	if (cnt >= 4) {	//若向上4代人都没问题，那就没问题了
//		return true;
//	}
//	//判断上一代
//	return (Find(fam[a].dad, fam[b].mom, cnt)	//判断当前两人的父母是不是近亲，两对父母，共有4中可能
//		&& Find(fam[a].mom, fam[b].dad, cnt)
//		&& Find(fam[a].mom, fam[b].mom, cnt)	
//		&& Find(fam[a].dad, fam[b].dad, cnt));
//}
//int main(void)
//{
//	int n;
//	cin >> n;
//	int id;
//	while (n--) {
//		cin >>id;
//		cin >> fam[id].sex >> fam[id].dad >> fam[id].mom;	
//		//也得将父母的编号对应的sex信息补充，不然之后会有3个测试点无法通过，
//		//虽然你知道父母的性别，但程序不知道呀，比如 输入 00001 M 11111 22222，需要你判断11111 22222可以结合吗，如果你不记录，程序并不知道11111 22222的性别
//		//虽然这个例子不够恰当，但会有此类需求需要你进行判断，所以也得将“本人”的父母的信息记下，便于之后判断
//		if (fam[id].dad != -1) {		
//			fam[fam[id].dad].sex = 'M';	
//		}
//		if (fam[id].mom != -1) {
//			fam[fam[id].mom].sex = 'F';
//		}
//	}
//	int m,a,b;
//	cin >> m;
//	while (m--) {
//		cin >> a >> b;	//输入情侣，进行判断
//		if (fam[a].sex == fam[b].sex) {
//			cout << "Never Mind" << endl;
//		}
//		else if (Find(a, b, 0)) {
//			cout << "Yes" << endl;
//		} else {
//			cout << "No" << endl;
//		}
//	}
//	return 0;
//}



//7 - 14 集合相似度
#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
int main()
{
	vector<vector<int>> vis;
	int N;
	cin >> N;
	while (N--) {
		int cnt;
		set<int> tmp;
		vector<int> ret;
		cin >> cnt;
		for (int i = 0; i < cnt; ++i) {
			int inp;
			cin >> inp;
			tmp.insert(inp);
		}
		for (auto i : tmp) {
			ret.push_back(i);
		}
		vis.push_back(ret);
	}
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		vector<int> j(min(vis[x].size(),vis[y].size()),0), b(vis[x].size()+vis[y].size(),0);
		auto jend = set_intersection(vis[x].begin(), vis[x].end(), vis[y].begin(), vis[y].end(), j.begin());
		auto bend = set_union(vis[x].begin(), vis[x].end(), vis[y].begin(), vis[y].end(), b.begin());
		int n1 = jend - j.begin();
		int n2 = bend - b.begin();
		printf("%.2lf%%\n", (n1*1.0/n2)*100);
	} 
	return 0;
}
