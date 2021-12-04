
//7-9 排座位 
//解一，每次需要同时找出两人的朋友，再进行比较，效率较低
#include<iostream>
using namespace std;
#include<vector>
#include<string.h>
//寻找朋友的朋友，需要dfs找出所有的朋友

int N, M, K;
bool flag[101];
void DFS(int u, vector<int>& v, vector<vector<int>>& ans) {
	flag[u] = true;
	for (int i = 1; i < N + 1; ++i) {
		if (ans[u][i] == 1 && flag[i] == false) {
			v.push_back(i);
			DFS(i, v, ans);
		}
	}

}
int main(void)
{
	cin >> N >> M >> K;
	vector<vector<int>> ans(N + 1, vector<int>(N + 1, 0));
	vector<int> v1, v2;

	for (int i = 0; i < M; ++i) {
		int x, y, rela;
		cin >> x >> y >> rela;
		ans[x][y] = rela;
		ans[y][x] = rela;
	}
	while (K--) {
		int x, y;
		cin >> x >> y;
		if (ans[x][y] == 1) {	//朋友关系
			cout << "No problem" << endl;
		} else if (ans[x][y] == 0) {	//不是朋友也不敌对
			cout << "OK" << endl;
		} else if (ans[x][y] == -1) {	//有敌对关系
			memset(flag, 0, 101);
			v1.clear();
			v2.clear();
			DFS(x, v1, ans);
			memset(flag, 0, 101);
			DFS(y, v2, ans);
			bool is = false;
			for (int i = 0; i < v1.size(); ++i) {	//比较二者是否有相同朋友
				for (int j = 0; j < v2.size(); ++j) {
					if (v1[i] = v2[j]) {
						cout << "OK but..." << endl;
						is = true;
						break;
					}
				}
				if (is)
					break;
			}
			if (!is) {
				cout << "No way" << endl;
			}

		}
	}
	return 0;
}


//解二，直接借助一个tag记录是否已在dfs过程中通过不断朋友关系找到对方
#include<cstdio>
#include<cstring>
int firends[120][120];
int vis[120][120];
int n, m, k, tag;
void dfs(int x, int y)
{
	if (tag)//已经找到共同的朋友 
		return;
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (vis[x][i])
			continue;
		if (firends[x][i] == 1)
		{
			if (i == y)
			{
				tag = 1;
				return;
			} else
			{
				vis[x][i] = vis[i][x] = 1;
				dfs(i, y);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int i, j;
	memset(firends, 0, sizeof(firends));//初始值均为0 
	while (m--)
	{
		int fa, fb, rat;
		scanf("%d%d%d", &fa, &fb, &rat);
		firends[fa][fb] = rat;
		firends[fb][fa] = rat;
	}
	for (i = 0; i < k; ++i)
	{
		int a, b;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &a, &b);//输入需要查询的2个人的编号
		tag = 0;
		if (firends[a][b] == 1)
		{
			printf("No problem\n");
			continue;
		}
		vis[a][b] = vis[b][a] = 1;
		dfs(a, b);//tag==1，代表2人有共同的朋友 
		if (firends[a][b] == -1)
		{
			if (tag)//有朋友 
				printf("OK but...\n");
			else//没有共同朋友 
				printf("No way\n");
		} else//firends[a][b]==0 
		{
			if (tag)//朋友的朋友还是朋友 
				printf("No problem\n");
			else//二个人什么关系都没有 
				printf("OK\n");
		}
	}
	return 0;
}

//解三，并查集
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 110;
int s[N][N];
int f[N];
int find(int x) {
	if (x == f[x])return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y) {
	int t1 = find(x);
	int t2 = find(y);
	if (t1 != t2)f[t1] = t2;
}
int main() {
	int n, m, k, x, y, z;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	while (m--) {
		cin >> x >> y >> z;
		s[x][y] = s[y][x] = z;
		if (z == 1)merge(x, y);
	}
	while (k--) {
		cin >> x >> y;
		if (s[x][y] == 1)puts("No problem");
		else if (s[x][y] == -1) {
			if (find(x) == find(y))puts("OK but...");
			else puts("No way");
		} else {
			if (find(x) == find(y))printf("No problem");
			else puts("OK");
		}

	}
	return 0;
}
