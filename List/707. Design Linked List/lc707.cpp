class MyLinkedList {

public:

    struct LinkedNode { // remember how to define a struct of a node. Pay attention! don't use the ListNode because it will conflicts with the struct inside leetcode
        LinkedNode* next;
        int val;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        _virtualhead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index >= _size || index < 0)
            return -1;
        LinkedNode* cur = _virtualhead->next;
        while (index-- > 0) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkedNode* NewNode = new LinkedNode(val);
        NewNode->next = _virtualhead->next;
        _virtualhead->next = NewNode;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode* NewNode = new LinkedNode(val);
        LinkedNode* cur = _virtualhead;
        while (cur->next != nullptr)  cur = cur->next;
        cur->next = NewNode;
        _size++;
    }

    void addAtIndex(int index, int val) { //pay attention! index starts from 0!
        if (index < _size && index >= 0) {
            LinkedNode* cur = _virtualhead;
            int times = index;
            while (times-- > 0) {
                cur = cur->next;
            }
            LinkedNode* NewNode = new LinkedNode(val);
            NewNode->next = cur->next;
            cur->next = NewNode;
            _size++;
        }
        else if (index == _size) {
            LinkedNode* NewNode = new LinkedNode(val);
            LinkedNode* cur = _virtualhead;
            while (cur->next != nullptr)  cur = cur->next;
            cur->next = NewNode;
            _size++;
        }
        return;
    }

    void deleteAtIndex(int index) {
        if (index < _size && index >= 0) {
            LinkedNode* cur = _virtualhead;
            while (index-- > 0)
                cur = cur->next;
            LinkedNode* p = cur->next;
            cur->next = cur->next->next;
            delete p;
            _size--;
        }
        return;
    }
private:
    int _size;
    LinkedNode* _virtualhead;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
