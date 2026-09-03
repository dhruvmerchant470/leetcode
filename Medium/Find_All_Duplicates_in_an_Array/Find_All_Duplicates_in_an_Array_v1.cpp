class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector <int>ans;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size()-1;i++)
       {
        if(nums.at(i)==nums.at(i+1))
        ans.push_back(nums.at(i));
       }
         
   return ans; 
   }
};