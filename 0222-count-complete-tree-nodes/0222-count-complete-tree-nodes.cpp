class Solution {
public:

    int leftHeight(TreeNode* root)
    {
        if(!root)
            return 0;

        return 1 + leftHeight(root->left);
    }

    int rightHeight(TreeNode* root)
    {
        if(!root)
            return 0;

        return 1 + rightHeight(root->right);
    }

    int count(TreeNode* root)
    {
        if(!root)
            return 0;

        if(leftHeight(root->left) == rightHeight(root->right))
            return (1LL << (leftHeight(root->left) + 1)) - 1;

        return 1 + count(root->left) + count(root->right);
    }

    int countNodes(TreeNode* root) {
        return count(root);
    }
};