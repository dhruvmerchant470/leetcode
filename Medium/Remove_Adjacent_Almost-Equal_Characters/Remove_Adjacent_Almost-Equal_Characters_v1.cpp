class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int size = word.size();
        int cnt=0;
        // sort(vec.begin(),vec.end());
        for(int i=0;i<size-1;i++){
            if(abs(word[i+1]-word[i])<=1){
                cnt++;
                if(i+2>=size) continue;
                else{
                    while(abs(word[i+1]-word[i])<=1 || abs(word[i+2]-word[i+1])<=1){
                        word[i+1]++;
                    }
                }
            }
        }
        return cnt;
    }
};