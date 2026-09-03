class Solution {
public:
    bool check(vector<int>& arr,int mid){
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=mid) cnt++;
            if(cnt>=mid) return true;
        }
        return false;
    }
    int hIndex(vector<int>& citations) {
        int low=0;
        int high=citations.size();
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(citations,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};