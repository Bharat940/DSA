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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prevNode = NULL;

        while (root != NULL) {
            if (root->left == NULL) {
                if (prevNode != NULL && prevNode->val > root->val) {
                    if (first == NULL) {
                        first = prevNode;
                    }
                    second = root;
                }
                prevNode = root;
                root = root->right;
            } else {
                TreeNode* IP = root->left;
                while (IP->right != NULL && IP->right != root) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    IP->right = root;
                    root = root->left;
                } else {
                    if (prevNode != NULL && prevNode->val > root->val) {
                        if (first == NULL) {
                            first = prevNode;
                        }
                        second = root;
                    }
                    prevNode = root;
                    IP->right = NULL;
                    root = root->right;
                }
            }
        }

        if (first != NULL && second != NULL) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};