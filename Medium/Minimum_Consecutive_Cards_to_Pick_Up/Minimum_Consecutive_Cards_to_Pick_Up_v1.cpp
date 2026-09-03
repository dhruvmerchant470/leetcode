class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int n=cards.size();
        unordered_map<int,int>mp;
        while(j<n){
            mp[cards[j]]++;
            if(mp[cards[j]]>1){
                while(cards[i]!=cards[j] || mp[cards[i]]>2){
                    mp[cards[i]]--;
                    i++;
                }
                ans=min(ans,j-i+1);
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};