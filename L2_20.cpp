//7-20 ���Ĺ�ע
#include<iostream> 
using namespace std;
#include<map>
#include<vector>
int main()
{
	int N;
	cin >> N;
	map<string, int> my;
	string name;
	while (N--) {	//����N��my��ע������Ϣ
		cin >> name;
		my[name] = 0;
	}

	int average = 0, sum = 0, cnt;
	cin >> N;
	int sumNumber = N;
	map<string,int> find;
	while (N--) {
		cin >> name >> cnt;
		find[name] = cnt;
		sum += cnt;
	}
	bool isHave = false;
	average = sum /sumNumber ;
	for (auto kv : find) {
		if (!my.count(kv.first) && kv.second>average) {	//û�ڹ�ע�б���
			cout << kv.first << endl;
			isHave = true;
		}
	}
	if (!isHave) {
		cout << "Bing Mei You";
	}

	return 0;
}

