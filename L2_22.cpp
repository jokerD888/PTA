#include<iostream>
using namespace std;
#include<map>
#include<vector>
struct Node
{
	string adress;
	int data;
	string next;
};
int main()
{
	vector<Node> ret;
	string head, next,rhead;
	int data,n;
	cin >> rhead >> n;
	
	map<string, pair<int, string>> nodes;
	for(int i=0;i<n;++i) {		//以节点地址为key,data和next为value
		cin >> head >> data >> next;
		nodes[head] = make_pair(data, next);
	}
	for (int i = 0; i < n; ++i) {		//利用map的特性，将链表串连起来
		next = nodes[rhead].second;
		ret.push_back({ rhead,nodes[rhead].first,next});
		rhead = next;
		if (rhead == "-1")	
			break;		//去除不在链中的多余节点
	}
	vector<pair<string, int>> result;
	int first = ret.size() - 1, second = 0;
	while (first >= second) {		//重排链表
		if (first != second) {		
			result.emplace_back(ret[first].adress, ret[first].data);
			result.emplace_back(ret[second].adress, ret[second].data);
		} else {	//奇数个节点
			result.emplace_back(ret[first].adress, ret[first].data);
		}
		--first;
		++second;
	}
	
	int len = result.size();
	for (int i = 0; i < len-1; ++i) {		//输出打印
		cout << result[i].first << ' ' << result[i].second << ' ' << result[i + 1].first << endl;
	}
	cout << result[len-1].first << ' ' << result[len-1].second << " -1" ;
	return 0;
}
