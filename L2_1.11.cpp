#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<cstring>

//7-1 旅游规划 (25 分)----------------------------------------------------------

struct edge {
	int v, w, c; //v为终点，路径为w,花费为c
};
struct Dis {
	int w, c;
	bool operator>(const Dis& a) const {
		if (w != a.w) return w > a.w;
		return c > a.c;
	}
};
struct node {
	Dis dis;   //代价
	int u;     //起点
	bool operator>(const node& a) const { return dis > a.dis; }
};

const int maxn = 510;
vector<edge> e[maxn];    //e[i]表示以i为起点的边集合

Dis dis[maxn];           //dis[i]代表源点到i点的距离
bool vis[maxn];          //标记是否走过
priority_queue<node, vector<node>, greater<node>> q;  // 小根堆，选出综合代价最小的边

void dijkstra(int s) {
	memset(dis, 63, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = { 0,0 };
	q.push({ {0,0},s });
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto ed : e[u]) {
			int v = ed.v, w = ed.w, c = ed.c;
			Dis to{ dis[u].w + w,dis[u].c + c };
			if (dis[v] > to) {
				dis[v] = to;
				q.push({ dis[v],v });
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N, M, S, D;
	scanf("%d%d%d%d", &N, &M, &S, &D);
	int x, y, len, w;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d%d", &x, &y, &len, &w);
		e[x].push_back({ y,len,w });
		e[y].push_back({ x,len,w });
	}
	dijkstra(S);
	cout << dis[D].w << " " << dis[D].c;
	return 0;
}
// 或
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 501;
const int INF = 501;
int road[maxn][maxn];
int cost[maxn][maxn];
int d[maxn]; //最短距离
int money[maxn]; //最少花费
bool vis[maxn] = { false }; //结点是否访问过
int n;
void dijkstra(int s) //s为起点
{
	fill(d, d + maxn, INF);  //初始化
	fill(money, money + maxn, INF);
	d[s] = 0;
	money[s] = 0;
	for (int i = 0; i < n; i++) {   //循环n次
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {  //找到未访问结点中最小的
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;			//标记为已访问
		for (int v = 0; v < n; v++) {  //优化的d[v]
			if (vis[v] == false && road[u][v] != INF && d[u] + road[u][v] < d[v]) {
				d[v] = d[u] + road[u][v];
				money[v] = money[u] + cost[u][v];
			} else if (vis[v] == false && road[u][v] != INF && d[u] + road[u][v] == d[v]) {
				if (money[u] + cost[u][v] < money[v]) {
					money[v] = money[u] + cost[u][v];
				}
			}
		}
	}
}
int main()
{
	int m, s, end;
	int v1, v2, length, c;
	cin >> n >> m >> s >> end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) road[i][j] = 0;
			else road[i][j] = maxn;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> length >> c;
		road[v1][v2] = road[v2][v1] = length;
		cost[v1][v2] = cost[v2][v1] = c;
	}
	dijkstra(s);
	cout << d[end] << " " << money[end];
	return 0;
}



//7-11 列车调度 (25 分)------------------------------------------------------
#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<algorithm>
//1.从input中读取数据的时候，倘若比队列中最小的队尾数据小，则添加到该队列的队尾处，
//否则，创建一个新的队列
//2.但为了节省空间，我们完全不需要真的建几个队列来进行模拟，只需要建立一个一维数组，
//数组中每一个元素的数值来代表队尾元素的值就行了。
//3.重点是判断插入那个“队列”，倘若不使用二分查找提交就直接超时了。
// 因为所建立的一维数组一定是有序的，所以可以使用二分查找
vector<int>track;
void BinarySearch(int a) {
	// 查找数组中第一个大于等于a的数的小标
	int l = 0, r = track.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a < track[mid]) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (l <= (int)track.size() - 1) {
		track[l] = a;
	} else {
		track.push_back(a);
	}
}

int main() {
	//8 4 2 1
	//5 3
	//9 6
	//7 升序二分
	int n, temp;
	cin >> n;
	while (n--) {
		cin >> temp;
		//BinarySearch(temp);
		// 或
		auto it = upper_bound(track.begin(), track.end(), temp);
		if (it != track.end()) {
			*it = temp;
		} else {
			track.push_back(temp);
		}
	}
	cout << track.size();
}