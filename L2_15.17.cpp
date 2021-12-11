//7-15 树的遍历
#include<iostream>
using namespace std;
#include<vector>
#include<map>

//建立中序遍历的节点与其下标的映射
map<int, int> m;
vector<vector<int>> ans;
void bfs(vector<int>& pos, vector<int>& in,int posL,int posR,int inL,int inR,int depth) {
	if (posL > posR)
		return;
	ans[depth].push_back(pos[posR]);
	int inIndex = m[pos[posR]];
	int cnt = inIndex - inL;
	bfs(pos, in, posL, posL + cnt - 1, inL, inIndex - 1,depth+1);
	bfs(pos, in, posL + cnt, posR - 1, inIndex + 1, inR,depth+1);
}
int main()
{
	int n;
	cin >> n;
	vector<int> pos, in;
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		pos.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		in.push_back(tmp);
		m[tmp] = i;
	}

	bfs(pos, in, 0, n - 1, 0, n - 1, 0);
	vector<int> ret;
	for (const auto& i : ans) {
		for (const auto& j : i) {
			ret.push_back(j);
		}
	}
	for (int i = 0; i < ret.size() - 1; ++i) {
		cout << ret[i] << ' ';
	}
	cout << ret[ret.size() - 1];
	return 0;
}


//7-17 最长对称子串
#include<iostream>
#include<string>
using namespace std;
int findMax(string& s, int pos, int parity) {
	int left = 0, right = s.size() - 1,ptrL,ptrR;
	int cnt = 0;

	if (parity == 1) {
		ptrL = pos, ptrR = pos + 1;
	} else if (parity == 2) {
		ptrL = pos - 1, ptrR = pos;
	} else {
		ptrL = pos - 1, ptrR = pos + 1;
		cnt = 1;
	}
	while (ptrL>=left && ptrR<=right) {
		if (s[ptrL--] == s[ptrR++]) {
			cnt += 2;
		} else {
			break;
		}
	}
	return cnt;
	
}
int findString(string& s) {
	int len = s.size();
	int cntMax = 0;;
	for (int i = 0; i < len; ++i) {
		cntMax = max(cntMax, findMax(s, i,0));
		cntMax = max(cntMax, findMax(s, i,1));
		cntMax = max(cntMax, findMax(s, i,2));
	}
	return cntMax;
}
int main()
{
	string s;
	getline(cin,s);
	cout<<findString(s);
	return 0;
}
