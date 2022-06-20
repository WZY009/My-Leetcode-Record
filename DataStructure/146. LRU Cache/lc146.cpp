struct myListNode{
   int key;
    myListNode* pre;
    myListNode* next;
    myListNode(int k): key(k), pre(nullptr), next(nullptr){}
};
struct Data{
    int val;
    myListNode* cur;
};

class LRUCache {
private:
    int maxSize;
    int curSize;
    myListNode* dummyHead;
    myListNode* dummyTail;
    unordered_map<int, Data> umap;
public:
    
    LRUCache(int capacity) {
        maxSize = capacity;
        curSize = 0; // Pay attention! you have to 
        dummyHead =  new myListNode(-1);
        dummyTail = new myListNode(-1);
        dummyHead->next = dummyTail;
        dummyTail->pre = dummyHead;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) return -1;
        myListNode* p = umap[key].cur;   
        
        p->pre->next = p->next;
        p->next->pre = p->pre;
        
        p->pre = dummyTail->pre;
        dummyTail->pre->next = p;
        p->next = dummyTail;
        dummyTail->pre = p;        
        
        return umap[key].val;
    }
    
    void put(int key, int value) {
        if(umap.find(key) == umap.end()) {
            if(curSize < maxSize) {
                myListNode* cur = new myListNode(key);
                cur->pre = dummyTail->pre;
                dummyTail->pre->next = cur;
                cur->next = dummyTail;
                dummyTail->pre = cur;
                umap[key].cur = cur;
                umap[key].val = value;
                curSize++;
            }
            else {
                myListNode* p = dummyHead->next;
                dummyHead->next = p->next;
                p->next->pre = dummyHead;
                umap.erase(p->key);
                delete p;
                myListNode* cur = new myListNode(key);
                cur->next = dummyTail;
                cur->pre = dummyTail->pre;
                dummyTail->pre->next = cur;
                dummyTail->pre = cur;          
                umap[key].cur = cur;
                umap[key].val = value;               
            }     
        }      
        else {
            myListNode* p = umap[key].cur;
            
            p->pre->next = p->next;
            p->next->pre = p->pre;
            p->pre = dummyTail->pre;
            dummyTail->pre->next = p;
            p->next = dummyTail;
            dummyTail->pre = p;
            umap[key].val = value;
        }    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */