
//7-8 抢红包
//测试点一未过，为考虑红包个数
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<map>
//#include<climits>
//
//int main(void)
//{
//	int N;
//	cin >> N;
//	vector<int>	p(N+1, 0);
//	for (int i = 1; i <= N; ++i) {
//		int m;
//		cin >> m;
//		int index, money,sum=0;
//		for (int j = 0; j < m; ++j) {
//			cin >> index >> money;
//			sum += money;
//			p[index] += money;
//		}
//		p[i] -= sum;
//	}
//	p[0] = INT_MIN;
//	for (int i = 1; i <= N; ++i) {
//		int max = p[0], index = 0;
//		for (int j = 1; j <= N; ++j)
//			if (max < p[j]) {
//				max = p[j];
//				index = j;
//			}
//		p[index] = INT_MIN;
//		printf("%d %.2lf\n", index, max / 100.0);
//	}
//
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//struct People
//{
//	int index;
//	int cnt;
//	int money;
//	//按最终的金额从达到小，金额相同，按红包个数从大到小，若个数也相同，按个人编号递增
//	bool operator<(const People a) const
//	{
//		if (money == a.money) {
//			if (cnt == a.cnt)
//				return index < a.index;
//			else
//				return cnt > a.cnt;
//		} else
//			return money > a.money;
//
//	}
//};
//int main(void)
//{
//	vector<People> ans;
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; ++i) {
//		People p;
//		p.index = i;
//		p.cnt = 0;
//		p.money = 0;
//		ans.push_back(p);
//	}
//
//	for (int i = 0; i < N; ++i) {
//		int m, x, mon;
//		cin >> m;
//		while (m--) {
//			cin >> x >> mon;
//			ans[i].money -= mon;
//			ans[x-1].cnt++;
//			ans[x-1].money += mon;
//		}
//	}
//	sort(ans.begin(), ans.end());
//	for (auto i : ans) {
//		printf("%d %.2lf\n", i.index+1, i.money / 100.0);
//	}
//	return 0;
//}

