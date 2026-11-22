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
    vector<int> rightSideView(TreeNode* root) {

        if(!root) { return {}; }
        
        queue<TreeNode*> _queue;
        _queue.push(root);

        vector<int> res;


        while(!_queue.empty()) {

            int queueSize = _queue.size();

            for(int i = 0; i < queueSize; i++) {

                auto node = _queue.front();
                _queue.pop();

                if(node->left) {
                    _queue.push(node->left);
                }

                if(node->right) {
                    _queue.push(node->right);
                }

                if(i == queueSize-1 && node != nullptr) {
                    res.push_back(node->val);
                }
            }
        }

        return res;

    }
};


/*

traverse level order and only record last node

*/