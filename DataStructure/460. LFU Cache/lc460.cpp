// The Gif:
// https://leetcode.cn/problems/lfu-cache/solution/chao-xiang-xi-tu-jie-dong-tu-yan-shi-460-lfuhuan-c/
struct MyNode{
    int val;
    int key;
    int freq;
    MyNode(int k, int v, int f) : key(k), val(v), freq(f) {}
};

class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, list<MyNode>> freqTable;
    unordered_map<int, list<MyNode>::iterator> keyTable;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        freqTable.clear();
        keyTable.clear();
    }
    
    int get(int key) {
        if(capacity == 0) return -1;
        auto it = keyTable.find(key);
        if(it == keyTable.end()) return -1;
        list<MyNode>::iterator node = it->second;
        int value = node->val;
        int curKey = node->key;
        int frequency = node->freq;
        freqTable[frequency].erase(node); // delete the node according to its frequency.
        if(freqTable[frequency].size() == 0) { // if the frequency is empty, you should delete it.
            freqTable.erase(frequency);
            if(minFreq == frequency) minFreq++; // Pay attention! Why the minFreq should add one? - Because if the node is the useless one and it is visited this time, the minimum frequency should come from the node. Thus, mindFreq++;
        }
        freqTable[frequency + 1].push_front(MyNode(curKey, value, frequency + 1)); // Add this node into freqTable
        keyTable[curKey] = freqTable[frequency + 1].begin(); // update the keyTable
        return value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto it = keyTable.find(key);
        if(it == keyTable.end()) {  // if you can't find the key in the key table
            if(capacity == keyTable.size()) { // If there are still some vacancies, you can put the node into it
                auto it2 = freqTable[minFreq].back();
                keyTable.erase(it2.key);
                freqTable[minFreq].pop_back();
                if(freqTable[minFreq].size() == 0) {
                    freqTable.erase(minFreq);
                }
            } 
            freqTable[1].push_front(MyNode (key, value, 1));
            keyTable[key] = freqTable[1].begin();
            minFreq = 1;                
            
        } else {
            list<MyNode>::iterator node = it->second;
            int frequency = node->freq;
            freqTable[frequency].erase(node);  // Attention! After this row, the node is released and you have no access to it! so you have to store all the data of node!
            if(freqTable[frequency].size() == 0) { 
                freqTable.erase(frequency);
                if(minFreq == frequency) minFreq++; 
            }
            freqTable[frequency + 1].push_front(MyNode(key, value, frequency + 1)); 
            keyTable[key] = freqTable[frequency + 1].begin();     
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */