class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        int mid=(s+e)/2;
        int ans=0;
        while(s<=e){
            if(arr[mid]<arr[mid+1]) s=mid+1;
            else if(arr[mid]<arr[mid-1]) e=mid-1;
            else {
                ans=mid;
                break;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};