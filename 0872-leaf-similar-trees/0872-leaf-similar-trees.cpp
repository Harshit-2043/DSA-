/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        collect(root1, a);
        collect(root2, b);
        return a == b;
    }
private:
    void collect(TreeNode* node, vector<int>& leaves) {
        if (!node) return;
        if (!node->left && !node->right) leaves.push_back(node->val);
        collect(node->left, leaves);
        collect(node->right, leaves);
    }
};