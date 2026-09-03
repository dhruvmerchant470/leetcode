class Solution {
public:
    
    char kthCharacter(long long k, vector<int>& operations) {
        string bin="";
        k=k-1;
        int cnt=0;
        int index=0;
        while(k>0){
            int tmp=k&operations[index];
            // char tmp1=tmp+'0';
            // bin.push_back(tmp1);
            cnt+=tmp;
            k=k>>1;
            index++;
        }
        // reverse(bin.begin(),bin.end());
        // cout<<bin.size()<<endl;
        // cout<<operations.size()<<endl;
        return 'a'+cnt%26;
    }
};