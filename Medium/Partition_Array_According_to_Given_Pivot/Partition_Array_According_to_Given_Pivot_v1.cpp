class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small,big,equal;
        for(auto it: nums){
            if(it<pivot) small.push_back(it);
            else if(it==pivot) equal.push_back(it);
            else big.push_back(it);
        }

        for(auto it: equal){
            small.push_back(it);
        }

        for(auto it: big){
            small.push_back(it);
        }
        return small;
    }
};