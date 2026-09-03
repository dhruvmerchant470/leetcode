class Solution {
public:
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>temp;
        set<int>::iterator it;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
           temp.insert(nums[i]);
        }
        set<int>temp1;
        set<int>::iterator it1;
        for(int i=0;i<nums.size();i++)
        {
            temp1.insert(i+1);
        }
        int i=0,j=0;
        it=temp.begin();it1=temp1.begin();
        while(it!=temp.end()&&it1!=temp1.end())
        {
            if(*it==*it1){ it++;it1++;}
            else {ans.push_back(*it1);it1++;}
        }
        while(it1!=temp1.end())
        {
            ans.push_back(*it1);
            it1++;
        }
        return ans;
    }
};