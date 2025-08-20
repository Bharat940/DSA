/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prevNode = NULL;

    int minDiffInBST(TreeNode* root) {
        if (root == NULL)
            return INT32_MAX;

        int ans = INT32_MAX;

        if (root->left != NULL) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        if (prevNode != NULL) {
            ans = min(ans, root->val - prevNode->val);
        }
        prevNode = root;

        if (root->right != NULL) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};