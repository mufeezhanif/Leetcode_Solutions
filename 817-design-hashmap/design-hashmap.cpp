class NewNode{
    public:
        int key, val;
        NewNode * next;
        NewNode(int key, int val){
            this->key = key;
            this->val = val;
            next = nullptr;
        }
};
class MyHashMap {
public:
    NewNode * head;
    NewNode* tail;
    MyHashMap() {
        head = nullptr;
        tail = head;
    }
    
    void put(int key, int value) {
        if(!head){
            head = new NewNode(key, value);
            tail = head;
            return;
        }
        NewNode *mover = head;
        while(mover){
            if(mover->key == key){
                mover->val = value;
                return ;
            }
            mover = mover->next;
        }
        tail->next = new NewNode(key, value);
        tail = tail->next;
    }
    
    int get(int key) {
        if(head==nullptr) return -1;
        NewNode * mover = head;
        while(mover){
            if(mover->key == key){
                return mover->val;
            }
            mover = mover->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(head==nullptr) return ;
        if(head->key == key){
            NewNode * temp = head;
            head = head->next;
            if(head==nullptr) tail = nullptr;
            delete temp;
            temp = nullptr;
            return ;
        }
        NewNode * mover = head;
        while(mover && mover->next){
            if(mover->next->key == key){
                NewNode * temp = mover->next;
                mover->next = mover->next->next;
                if(temp == tail) tail = mover;
                delete temp;
                temp = nullptr;
                return;
            }
            mover= mover->next;
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