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
private:

    int res{};


public:
    int goodNodes(TreeNode* root) {
        findGoodNodes(root, -100);
        return res;
    }


    void findGoodNodes(TreeNode* root, int maxNodeVal) {
        if(root == nullptr) { return; }

        if(root->val >= maxNodeVal) { res++; }

        findGoodNodes(root->left, max(root->val, maxNodeVal));
        findGoodNodes(root->right, max(root->val, maxNodeVal));
        return;
    }
};

/*

- Track max as we recurse down tree

- travers whole tree

- bubble up occurances of good nodes

*/
