/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* node)
{
    if(node == NULL)
        return 0;
    int lheight = height(node -> left);
    int rheight = height(node -> right);
    if(rheight == -1 || lheight == -1 || abs(lheight - rheight) > 1)
        return -1;
    return (lheight > rheight ? lheight : rheight)+1;
}
bool isBalanced(struct TreeNode* root) {
    if(height(root) == -1)
        return false;
    else
        return true;
}