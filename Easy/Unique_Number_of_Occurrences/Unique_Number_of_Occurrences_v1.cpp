class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       vector<int>ans;
       int i=0;
       int size=arr.size();
       sort(arr.begin(),arr.end());
       while(i<size)
       {
        int count=1;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        ans.push_back(count);
        i+=count;
       } 
       sort(ans.begin(),ans.end());
       for(int i=0;i<ans.size()-1;i++)
       {
        if(ans[i]==ans[i+1])
        return false;
        
       }
       return true;
    }
};