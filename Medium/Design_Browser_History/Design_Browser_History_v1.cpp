class Node{
    public:
    string data;
    Node* prev;
    Node* next;

    Node(){
        prev=NULL;
        next=NULL;
    }
    Node(string data){
        prev=NULL;
        next=NULL;
        this->data=data;
    }

};

class BrowserHistory {
public:
  
    
    Node* curr;
   
    BrowserHistory(string homepage) {
        Node* head =new Node(homepage);
        curr=head;
    }
    
    void visit(string url) {
        Node *tmp=new Node(url);
        curr->next=tmp;
        tmp->prev=curr;
        curr=tmp;
       
    }
    
    string back(int steps) {
        
        while(curr->prev!=NULL&&steps--){
            curr=curr->prev;
        }
        
        return curr->data;
    }
    
    string forward(int steps) {
        
        while(curr->next!=NULL&&steps--)
        {
            curr=curr->next;
        }
       
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */