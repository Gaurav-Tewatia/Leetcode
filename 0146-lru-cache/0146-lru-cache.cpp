class LRUCache {
public:
    class node{
        public:
        int key,value;
        node*next,*prev;
        node(int key,int value){
            this->key=key;
            this->value=value;
        }
    };
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int size;
    
    void addnode(node*n){
        n->next=head->next;
        n->prev=head;
        head->next->prev=n;
        head->next=n;
    }
    
    void deletenode(node*n){
        node*pre=n->prev;
        node*nex=n->next;
        pre->next=nex;
        nex->prev=pre;
    }
    
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
            tail->prev=head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            node*temp=mp[key];
            int res=temp->value;
            deletenode(temp);
            addnode(temp);
            mp.erase(key);
            mp[key]=head->next;
            return res;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            node*temp=mp[key];
            deletenode(temp);
            mp.erase(key);
        }
        else if(mp.size()==size){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */