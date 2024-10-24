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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Base case: both nodes are null, they are equivalent
        if (root1 == nullptr && root2 == nullptr) return true;

        // If one of them is null and the other is not, they are not equivalent
        if (root1 == nullptr || root2 == nullptr) return false;

        // If the values are not the same, they are not equivalent
        if (root1->val != root2->val) return false;

        // Check both without flip and with flip
        bool noSwap = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool swap = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

        // Return true if either no-swap or swap works
        return noSwap || swap;
    }
};
