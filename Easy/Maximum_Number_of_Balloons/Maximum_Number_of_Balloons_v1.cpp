class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cntB=0,cntA=0,cntL=0,cntO=0,cntN=0;
        for(char it: text){
            if(it=='b') cntB++;
            else if(it=='a') cntA++;
            else if(it=='l') cntL++;
            else if(it=='o') cntO++;
            else if(it=='n') cntN++;
        }
        // cout<<cntA<<" "<<cntB<<" "<<cntL<<" "<<cntO<<" "<<cntN<<endl;
        return min(cntA,min(cntB,min(cntL/2,min(cntO/2,cntN))));
    }
};