class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int cnt=0;
        unordered_map<char,int>mp;
        while(right<s.length()){
            mp[s[right]]++;
            // bool flag = false;
            while(mp.size()==3 && left<=right){
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
                // flag = true;
            }
            // cout<<left<<" "<<right<<endl;
            cnt+=(left);
            right++;
        }
        return cnt;
    }
};