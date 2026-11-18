class MyHashMap {
private:

    struct Node {
        int key;
        int value;
        Node* next;
    };

    Node* hashMap[1000];

public:
    MyHashMap() {
        for(int i = 0; i<1000; i++) {
            hashMap[i] =  nullptr;
        }
    }
    
    void put(int key, int value) {
        int hashKey = key % 1000;

        if (hashMap[hashKey] == nullptr) {
            hashMap[hashKey] = new Node(key, value, nullptr);
            return;
        }

        Node* node = nullptr;
        
        while(node->next != nullptr) {
            if (node->key == key) {
                node->value = value;
                return;
            }
            node = node->next;
        }

        node->next = new Node(key, value, nullptr);
    }
    
    int get(int key) {
        int hashKey = key % 1000;

        if (hashMap[hashKey] == nullptr) {
            return -1;
        }

        Node* node =  hashMap[hashKey];
        while(node != nullptr) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }
        return -1;
    }
    
void remove(int key) {
    int hashKey = key % 1000;

    Node* node = hashMap[hashKey];
    Node* prev = nullptr;

    while (node != nullptr) {
        if (node->key == key) {
            if (prev == nullptr) {
                // deleting head
                hashMap[hashKey] = node->next;
            } else {
                prev->next = node->next;
            }

            delete node;
            return; // stop after deletion
        }

        prev = node;
        node = node->next;
    }
}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */