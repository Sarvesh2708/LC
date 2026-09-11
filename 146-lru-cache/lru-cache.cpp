class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

    unordered_map<int, Node*> mpp;
    int capacity;


    // Add node immediately after head
    void addNode(Node* node) {
        Node* nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        head->next = node;
        nextNode->prev = node;
    }


    // Remove node from linked list
    void delNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    LRUCache(int capacity) {

        this->capacity = capacity;

        // Dummy head and tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }


    int get(int key) {

        // Key doesn't exist
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];

        int ans = node->value;

        // Move node to front
        delNode(node);
        addNode(node);

        return ans;
    }


    void put(int key, int value) {

        // Key already exists
        if(mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            // Remove from current position
            delNode(node);

            // Update value
            node->value = value;

            // Move to front
            addNode(node);

            return;
        }


        // Cache is full
        if(mpp.size() == capacity) {

            // Least recently used node
            Node* lru = tail->prev;

            // Remove from map
            mpp.erase(lru->key);

            // Remove from linked list
            delNode(lru);

            // Free memory
            delete lru;
        }


        // Create new node
        Node* node = new Node(key, value);

        // Add to hashmap
        mpp[key] = node;

        // Add to front
        addNode(node);
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */