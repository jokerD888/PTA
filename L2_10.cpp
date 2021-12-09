//7-10 ��ת������
// ��һ��
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!preorder.size()) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[0]);
		stack<TreeNode*> stk;		//ά������ǰ�ڵ�����л�û�п��ǹ��Ҷ��ӵ����Ƚڵ㡹
		stk.push(root);
		int inorderIndex = 0;	//ָ�����������ĳ��λ��,��Ӧ�Ľڵ��ǡ���ǰ�ڵ㲻�������ߴﵽ�����սڵ㡹
		for (int i = 1; i < preorder.size(); ++i) {
			int preorderVal = preorder[i];
			TreeNode* node = stk.top();
			if (node->val != inorder[inorderIndex]) {	//ջ��Ԫ�ز�����inorderIndex��ָ�ڵ�Ļ�������ǰ�ڵ��ջ
				node->left = new TreeNode(preorderVal);		//����ǰ�ڵ���Ϊջ���ڵ������
				stk.push(node->left);
			} else {	//��ȵĻ������ϵĳ�ջ��inorderIndex++,ֱ�����߲����
				while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {	
					node = stk.top();
					stk.pop();
					++inorderIndex;
				}
				//��inorderIndex��ָ�ڵ���Ϊ����ջ�Ľڵ���Һ���
				node->right = new TreeNode(preorderVal);
				stk.push(node->right);
			}
		}
		return root;
	}
};
void BFS(TreeNode* root) {
	if (!root)
		return;
	queue<TreeNode*> Q;
	vector<int> ans;
	Q.push(root);
	while (!Q.empty()) {
		TreeNode* node = Q.front();
		Q.pop();
		ans.push_back(node->val);
		if (node->right)
			Q.push(node->right);
		if (node->left)
			Q.push(node->left);
	}
	int n = ans.size();
	for (int i = 0; i < n-1; ++i) {
		cout << ans[i] << ' ';
	}
	cout << ans[n - 1];
	return;

}
int main()
{
	int N;
	cin >> N;
	vector<int> inOrder;
	vector<int> preOrder;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		inOrder.push_back(tmp);
	}
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		preOrder.push_back(tmp);
	}
	TreeNode* root = Solution().buildTree(preOrder, inOrder);
	BFS(root);
	

	return 0;
}


//�����
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;
const int N = 50;
int in[N], pre[N], level[100000];
int cnt = 0;
int n;
//�����������洢�ڵ㣬��Ϊ��Ҫ���淴ת�����踸�ڵ��±�Ϊindex,����2*index+1,�Һ���2*index�����ձ������鼴Ϊ�𰸵�˳��
void dfs(int root, int start, int end, int index) {
	if (start > end) return;
		int i = start;
	while (i < end && in[i] != pre[root]) i++;	//��pre[root]��in�����е�λ��
	level[index] = pre[root];
	dfs(root + 1, start, i - 1, 2 * index +1);//��������Ľ���㻻λ�ã�����ߺ��ұ߽�㻻λ�á�
	dfs(root + (i - start + 1), i + 1, end, 2 * index );
}
int main() {
	scanf("%d", &n);
	memset(level, -1, sizeof level);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	dfs(0, 0, n - 1, 1);
	for (int i = 1; i < 10000; i++) {
		if (level[i] != -1 && cnt != n - 1) {
			printf("%d ", level[i]);
			cnt++;
		} else if (level[i] != -1) {
			printf("%d", level[i]);
			break;
		}
	}
	return 0;
}
