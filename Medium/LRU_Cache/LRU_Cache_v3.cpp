class Node{
    public:
    int val;
    int key;
    Node* prev;
    Node* next;
};

void insertAtHead(Node* &node,Node* &head){
    Node* tmp=head->next;
    head->next=node;
    node->next=tmp;
    node->prev=head;
    tmp->prev=node;
}


void deleteNode(Node* &node){
    node->prev->next=node->next;
    node->next->prev=node->prev;
}
class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        // cout<<mp.size()<<endl;
        if(mp.find(key)==mp.end()) return -1;
        auto tmp=mp[key];
        // cout<<"hi1"<<endl;
        deleteNode(tmp);
        insertAtHead(tmp,head);
        return tmp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto tmp=mp[key];
            tmp->val=value;
            deleteNode(tmp);
            insertAtHead(tmp,head);
        }
        else{
            if(mp.size()==cap){
                Node* prev=tail->prev;
                mp.erase(prev->key);
                deleteNode(prev);
            }

            Node* n1=new Node();
            n1->key=key;
            n1->val=value;
            mp[key]=n1;

            insertAtHead(n1,head);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */