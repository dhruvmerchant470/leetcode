class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size=arr.size();int ans;
        for(int i=0;i<size-1;i++)
            {
                if(arr[i]>arr[i+1])
                {ans=i;break;}
            }
            return ans;
    }
};