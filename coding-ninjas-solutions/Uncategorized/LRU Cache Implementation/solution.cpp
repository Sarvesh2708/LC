```cpp
#include <unordered_map>
using namespace std;

class LRUCache
{
public:

    class Node
    {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value)
        {
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

    LRUCache(int capacity)
    {
        this->capacity = capacity;

        // Dummy head and dummy tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Add node immediately after head
    void addNode(Node* node)
    {
        Node* nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        head->next = node;
        nextNode->prev = node;
    }

    // Delete node from the linked list
    void delNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key)
    {
        // Key does not exist
        if (mpp.find(key) == mpp.end())
        {
            return -1;
        }

        // Get the node
        Node* node = mpp[key];

        int ans = node->value;

        // Move this node to the front
        // because it is recently used
        delNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int value)
    {
        // If key already exists
        if (mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];

            // Remove from current position
            delNode(node);

            // Update value
            node->value = value;

            // Move to front
            addNode(node);

            return;
        }

        // If cache is full
        if (mpp.size() == capacity)
        {
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

        // Store key -> node
        mpp[key] = node;

        // New node is most recently used
        addNode(node);
    }
};
```
