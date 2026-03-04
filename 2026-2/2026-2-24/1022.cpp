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
    int sumRoot(TreeNode* root, int n)
    {
        if(root == NULL)
            return 0;
        if(root -> left == NULL && root -> right == NULL)
            return 2*n + root -> val;
        return sumRoot(root -> left, 2*n+root -> val)+sumRoot(root -> right, 2*n+root -> val);
    }
    int sumRootToLeaf(TreeNode* root) {
        return sumRoot(root, 0);
    }
};