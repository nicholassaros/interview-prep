/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        
        std::set<ListNode*> numSet;

        while(headA) {
            numSet.insert(headA);
            headA = headA->next;
        }

        while(headB) {
            if(numSet.contains(headB)) {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;

    }
};