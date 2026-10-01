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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;

        while (!q.empty()) {
            int pre;
            int n = q.size();
            if (level % 2 == 0) {
                pre = 0;
                while (n--) {
                    TreeNode* node = q.front();
                    q.pop();

                    if (node->val <= pre || node->val % 2 == 0)
                        return false;

                    pre = node->val;

                    if (node->left)
                        q.push(node->left);

                    if (node->right)
                        q.push(node->right);

                    
                }
            } else {
                pre = INT_MAX;
                while (n--) {
                    TreeNode* node = q.front();
                    q.pop();

                    if (node->val >= pre || node->val % 2 != 0)
                        return false;

                    pre = node->val;

                    if (node->left)
                        q.push(node->left);

                    if (node->right)
                        q.push(node->right);

                    
                }
            }

            level++;
        }

        return true;
    }
};