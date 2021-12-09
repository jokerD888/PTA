//7-10 玩转二叉树
// 解一：
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
		stack<TreeNode*> stk;		//维护「当前节点的所有还没有考虑过右儿子的祖先节点」
		stk.push(root);
		int inorderIndex = 0;	//指向中序遍历的某个位置,对应的节点是「当前节点不断往左走达到的最终节点」
		for (int i = 1; i < preorder.size(); ++i) {
			int preorderVal = preorder[i];
			TreeNode* node = stk.top();
			if (node->val != inorder[inorderIndex]) {	//栈顶元素不等于inorderIndex所指节点的话，将当前节点进栈
				node->left = new TreeNode(preorderVal);		//将当前节点作为栈顶节点的左孩子
				stk.push(node->left);
			} else {	//相等的话，不断的出栈，inorderIndex++,直到两者不相等
				while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {	
					node = stk.top();
					stk.pop();
					++inorderIndex;
				}
				//将inorderIndex所指节点作为最后出栈的节点的右孩子
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


//解二：
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;
const int N = 50;
int in[N], pre[N], level[100000];
int cnt = 0;
int n;
//借助数组来存储节点，因为需要镜面反转，假设父节点下标为index,左孩子2*index+1,右孩子2*index。最终遍历数组即为答案的顺序
void dfs(int root, int start, int end, int index) {
	if (start > end) return;
		int i = start;
	while (i < end && in[i] != pre[root]) i++;	//找pre[root]在in中序中的位置
	level[index] = pre[root];
	dfs(root + 1, start, i - 1, 2 * index +1);//这里巧妙的将结点换位置，将左边和右边结点换位置。
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
