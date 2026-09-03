class StockSpanner {
public:
    vector<int>ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int i;
        int n = ans.size();
        for(i = n-2;i>=0;i--){
            if(ans[i]>price) break;
        }
        return n-i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */