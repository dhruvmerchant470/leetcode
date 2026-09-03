class StockSpanner {
public:
    stack<int>s;
    vector<int>ans;
    StockSpanner() {
        s.push(-1);
    }
    
    int next(int price) {
        ans.push_back(price);
        int n=ans.size();
        int i;
        for(i=n-2;i>=0;i--){
           if(price<ans[i]) break;
        }
        return n-i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */