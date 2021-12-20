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
	for(int i=0;i<n;++i) {		//�Խڵ��ַΪkey,data��nextΪvalue
		cin >> head >> data >> next;
		nodes[head] = make_pair(data, next);
	}
	for (int i = 0; i < n; ++i) {		//����map�����ԣ�������������
		next = nodes[rhead].second;
		ret.push_back({ rhead,nodes[rhead].first,next});
		rhead = next;
		if (rhead == "-1")	
			break;		//ȥ���������еĶ���ڵ�
	}
	vector<pair<string, int>> result;
	int first = ret.size() - 1, second = 0;
	while (first >= second) {		//��������
		if (first != second) {		
			result.emplace_back(ret[first].adress, ret[first].data);
			result.emplace_back(ret[second].adress, ret[second].data);
		} else {	//�������ڵ�
			result.emplace_back(ret[first].adress, ret[first].data);
		}
		--first;
		++second;
	}
	
	int len = result.size();
	for (int i = 0; i < len-1; ++i) {		//�����ӡ
		cout << result[i].first << ' ' << result[i].second << ' ' << result[i + 1].first << endl;
	}
	cout << result[len-1].first << ' ' << result[len-1].second << " -1" ;
	return 0;
}
