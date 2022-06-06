// 2022 5.26 23：45 - (Unsolved)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>::iterator it;
    vector<int> values;
    void DFS(const vector<NestedInteger>& nestedList) {
        for(auto& nest : nestedList) {
            if(nest.isInteger()) values.push_back(nest.getInteger());   
            else  DFS(nest.getList()); 
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        DFS(nestedList);
        it = values.begin();
    }
    
    int next() {
        return *(it)++;
    }
    
    bool hasNext() {
        if(it != values.end()) return true;
        else return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */