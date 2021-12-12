//7-18 人以群分
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,tmp;
	vector<int> ans;
	cin >> n;

	while (n--) {
		cin >> tmp;
		ans.push_back(tmp);
	}

	sort(ans.begin(), ans.end());
	n = ans.size();
	int out, in;
	out = in = n / 2;

	if (n % 2) {
		int pos = out + 1;
		if ((ans[pos + 1] - ans[pos]) > (ans[pos] - ans[pos - 1])) {
			--in;
		} else {
			++out;
		}
	
	}
	int diff=0;
	for (int i = 0; i < ans.size(); ++i) {
		if (i < in)
			diff -= ans[i];
		else
			diff += ans[i];
	}
	cout << "Outgoing #: " << out << endl;
	cout << "Introverted #: " << in << endl;
	cout << "Diff = " << diff;
	return 0;
}
