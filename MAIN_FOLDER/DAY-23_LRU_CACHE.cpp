#include<bits/stdc++.h>


using namespace std;



class LRUCache{

    private:
        
    // A PUBLIC NODE CLASS.
    struct Node{
        
        int key, value;
        Node* prev;
        Node* next;
        
        // USER DEFINED DEFAULT CONSTRUCTOR.
        Node(int k=0, int v=0){
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
        
    };

        unordered_map<int, Node*> cache; //MAPS KEYS TO NODES.
        Node* head;
        Node* tail;
        
        int capacity;
        int size;

        // Removes a node from the linked list
        void removeNode(Node* node){
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            if(prevNode){
                prevNode->next = nextNode;
            }
            if(nextNode){
                nextNode->prev = prevNode;
            }
        }

        // Adds a node to the front (most recently used position)
        void addNodeToFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            if(head->next){
                head->next->prev = node;
            }
            head->next = node;
            if(tail->prev == head){
                tail->prev = node;
            }
        }

        // Evicts the least recently used node
        void evictLRU() {
            Node* lru = tail->prev;
            if (lru == head) return; // No valid LRU to evict
            cache.erase(lru->key);
            removeNode(lru);
            delete lru;
            size--;
        }

    public:
        LRUCache(int cap) : capacity(cap), size(0) {
            head = new Node(0, 0); // Dummy head
            tail = new Node(0, 0); // Dummy tail
            head->next = tail;
            tail->prev = head;
        }

        ~LRUCache(){
            Node* curr = head;
            while(curr){
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
        }

        int get(int key){
            
            if(cache.find(key) == cache.end()){
                return -1;
            }
            
            Node* node = cache[key];
            removeNode(node);
            addNodeToFront(node);
            return node->value;
        }

        void put(int key, int value){
            if(cache.find(key) != cache.end()){
                Node* node = cache[key];
                node->value = value;
                removeNode(node);
                addNodeToFront(node);
            }
            else{
                if(size == capacity){
                    evictLRU();
                }
                Node* newNode = new Node(key, value);
                cache[key] = newNode;
                addNodeToFront(newNode);
                size++;
            }
        }
        
};





int main(){

    LRUCache* cache = new LRUCache(2);
    
    cache->put(1, 1);
    cache->put(2, 2);

    cout << cache->get(1) << endl; // returns 1
    
    cache->put(3, 3); // evicts key 2
    
    cout << cache->get(2) << endl; // returns -1 (not found)
    
    cache->put(4, 4); // evicts key 1
    
    cout << cache->get(1) << endl; // returns -1 (not found)
    
    cout << cache->get(3) << endl; // returns 3
    
    cout << cache->get(4) << endl; // returns 4
    
    delete cache;
    

return 0;
}