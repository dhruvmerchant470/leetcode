class Solution {
public:
    string ans;
    int n_;
    string curr;
    int count;
    int k_;
    void generate(int index){
        if(index==n_){
            count++;
            // ans.push_back(curr);
            if(count==k_) ans=curr;
            return;
        }
        for(char c= 'a';c<='c';c++){
            if(index>0 && curr[index-1]==c) continue;
            curr.push_back(c);
            generate(index+1);
            if(ans!="") return;
            curr.pop_back();
        }

    }
    string getHappyString(int n, int k) {
        if(n==0) return "";
        n_=n;
        k_=k;
        generate(0);
        // for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
        return ans;
    }
};