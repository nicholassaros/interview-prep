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
struct Result {
    int height;
    bool balanced;

    Result(int _height, bool _balanced)
    : height(_height), balanced(_balanced){}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        Result res = balance(root);
        return res.balanced;
    }

    Result balance(TreeNode* node){
        if (node == nullptr) {
            return Result(0,true);
        }

        // check if balanced
        Result left_result = balance(node->left);
        Result right_result = balance(node->right);

        if(left_result.balanced == false || right_result.balanced == false){
            return Result(0,false);
        }

        if(abs(left_result.height - right_result.height) > 1){
            return Result(0,false);
        }
        return Result(max(left_result.height, right_result.height)+1,true);
    }
};

// struct with bool, int
// we want to return the max height of the subtree
// we want to return a boolean at each node as if the balance condition 
// is ever false we should always return false


