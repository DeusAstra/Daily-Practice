/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
function height(node)
{
    if(node == undefined)
        return 0;
    let lheight = height(node.left);
    let rheight = height(node.right);
    if(rheight == -1 || lheight == -1 || Math.abs(lheight - rheight) > 1)
        return -1;
    return (lheight > rheight ? lheight : rheight)+1;
}
var isBalanced = function(root) {
    if(height(root) == -1)
        return false;
    else
        return true;
};