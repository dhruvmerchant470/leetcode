class Solution {
public:
    char kthCharacter(int k) {
        int cnt=0;
        int tmp=k-1;
        while(tmp>0){
            cnt+=(tmp&1);
            tmp=tmp>>1;
        }
        return 'a'+cnt%26;
    }
};