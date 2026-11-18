/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        std::unordered_map<Node*, Node*> nodeCache;
        
        Node* dummyHead = new Node{0};
        Node* temp = dummyHead;

        while(head != nullptr) {

            if (!nodeCache.contains(head)) {
                nodeCache[head] = new Node{head->val};
            }
            temp->next = nodeCache[head];

        
            if (head->random == nullptr) {
                temp->next->random = nullptr;
            } else {
                if (!nodeCache.contains(head->random)) {
                    nodeCache[head->random] = new Node{head->random->val};
                }

                temp->next->random = nodeCache[head->random];
            }

            temp = temp->next;
            head = head->next;
        }

        return dummyHead->next;

    }
};


/*

    Deep copy the list including the random pointers
    We should itterate over the old list and create both the new node and the random node
    When we try to create the next node, we check out cache to see if we have a node with the value we are looking for
    If so we link the existing node and then continue
    If not we create it 



    Generate Node
        - Check Node Cache. 
            - If hit then use existing node
            - If not create new and add to cache.

    Generate Random Pointer
        - Check Node Cache. 
            - If hit use existing node
            - If not create new and add to cache.
*/