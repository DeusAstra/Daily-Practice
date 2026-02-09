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
    vector<TreeNode*> a;
    void LMR(TreeNode* node) {
        if(node == nullptr || node == NULL)
            return ;
        LMR(node -> left);
        a.push_back(node);
        LMR(node -> right);
    }
    TreeNode* buildTree(int l, int r) {
        if(l > r)
            return nullptr;
        int mid = (l + r) /2;
        //printf("building val = %d\n", a.at(mid) -> val);
        TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
        newnode = new TreeNode(a.at(mid) -> val, buildTree(l,mid-1), buildTree(mid+1,r));
        return newnode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        a.clear();
        LMR(root);
        int len = a.size();
        return buildTree(0, len-1);
    }
};