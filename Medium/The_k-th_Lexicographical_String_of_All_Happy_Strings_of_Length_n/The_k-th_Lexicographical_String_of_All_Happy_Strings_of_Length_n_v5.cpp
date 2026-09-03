class Solution {
public:
    vector<string>ans;
    int n_;
    string curr;
    void generate(int index){
        if(index==n_){
            ans.push_back(curr);
            return;
        }
        for(char c= 'a';c<='c';c++){
            if(index>0 && curr[index-1]==c) continue;
            curr.push_back(c);
            generate(index+1);
            curr.pop_back();
        }

    }
    string getHappyString(int n, int k) {
        if(n==0) return "";
        n_=n;
        generate(0);
        // for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
        if(k>ans.size()) return "";
        return ans[k-1];
    }
};