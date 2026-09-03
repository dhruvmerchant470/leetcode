class Queue{
public:
    int *A;
    int size;
    int head,tail;
    Queue(){
        size=INT_MAX;
        A=new int[INT_MAX];
        head=tail=0;
    }
    void push(int data){
        A[tail]=data;
        tail++;
    }
    int pop(){
        int ans=A[head];
        head++;
        if(head==tail){
            head=tail=0;
        }
        return ans;
    }
    int pop_back(){
        int ans=A[--tail];
        
        if(head==tail){
            head=tail=0;
        }
        return ans;
    }
    int front(){
        return A[head];
    }
    int size1(){
        return tail-head;

    }
    bool isEmpty(){
        return head==tail;
    }
    int back(){
        return A[tail-1];
    }
    
    
};
void print(Queue Q){
    while(!Q.isEmpty()){
      cout<<Q.pop()<<" ";
    }
    cout<<endl;
}
void spill(Queue &Q1,Queue &Q2){
    while(!Q1.isEmpty()){
        Q2.push(Q1.pop_back());
    }
}

class MyStack {
public:
Queue Q1,Q2;
    MyStack() {  
     };
    
    void push(int x) {
        Q1.push(x);
    }
    
    int pop() {
      return Q1.pop_back();
    }
    
    int top() {
        if(!Q1.isEmpty())
        return Q1.back();
        else{
           return Q2.front();
        }
    }
    
    bool empty() {
        return Q1.size1()+Q2.size1()==0?true:false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */