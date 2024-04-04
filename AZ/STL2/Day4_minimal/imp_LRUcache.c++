/*

LRU Cache

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.


Input Format

Implement the LRUCache class:

LRUCache(int capacity) : Initialize the LRU cache with positive size capacity.
int get(int key) : Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) : Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

Output Format

For every call to the get function print the value of the key if it exists else print -1.


Constraints

1 ≤ capacity ≤ 105

1 ≤ key, value ≤ 105

At most 105 calls will be made to functions get and put.


Sample Input 1

9 2
put 1 1
put 2 2
get 1
put 3 3
get 2
put 4 4
get 1
get 3
get 4

Sample Output 1

1
-1
-1
3
4

Note

The cache after every operation is:

[{1,1}]
[{1,1},{2,2}]
[{2,2},{1,1}]
[{1,1},{3,3}]
[{1,1},{3,3}]
[{3,3},{4,4}]
[{3,3},{4,4}]
[{4,4},{3,3}]
[{3,3},{4,4}]*/


#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (cache.size() >= capacity) {
                Node* lastNode = popTail();
                cache.erase(lastNode->key);
                delete lastNode;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
        }
    }
};
