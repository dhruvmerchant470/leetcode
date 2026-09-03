class Solution {
public:
    int cnt(int num){
        int prev, next, curr;
        prev = num%10;
        num/=10;
        int waive=0;
        while(num>9){
            curr = num%10;
            num/=10;
            next = num%10;
            if((curr>next && curr>prev) || (curr<next && curr<prev)) waive+=1;
            prev = curr;
        }
        return waive;
    }
    int totalWaviness(int num1, int num2) {
        int tot=0;
        for(int i=num1;i<=num2;i++){
            tot+=cnt(i);
        }
        return tot;
    }
};