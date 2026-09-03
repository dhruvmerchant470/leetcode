class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowD = to_string(low).size();
        int highD = to_string(high).size();
        vector<int>ans;
        for(int i=lowD;i<=highD;i++){
            for(int start = 1; start<=10-i; start++){
                int num=0;
                for(int d = start;d<start+i;d++){
                    num = num *10+d;
                }
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};