#include <stdint.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == NULL || q == NULL)
			return NULL;
		if (max(p->val, q->val) < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (min(p->val, q->val) > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};