class Solution {
public:
    void merge(vector<int>&arr,long long s,long long e,long long &cnt){
        long long mid=s+(e-s)/2;
        long long len1=mid-s+1;
        long long len2=e-mid;
        long long *arr1=new long long[len1];
        long long *arr2=new long long[len2];
        long long mIndex=s;
        for(long long i=0;i<len1;i++,mIndex++) arr1[i]=arr[mIndex];
        for(long long i=0;i<len2;i++,mIndex++) arr2[i]=arr[mIndex];
        mIndex=s;
        long long i=0,j=0;
        while(i<len1&&j<len2){
            if(arr1[i]>2*arr2[j]){
                cnt+=(len1-i); 
                j++;
            }
            else{
                i++;
            }
        }
        i=0;j=0;
        while(i<len1&&j<len2){
            if(arr1[i]>arr2[j]){
                arr[mIndex++]=arr2[j++];
            }
            else{
                arr[mIndex++]=arr1[i++];
            }
        }
        while(i<len1){
            arr[mIndex++]=arr1[i++];
        }
        while(j<len2) arr[mIndex++]=arr2[j++];
    }
    
    void mergeSort(vector<int>&arr,long long s,long long e,long long &cnt){
        if(s>=e) return;
        
        long long mid=s+(e-s)/2;
        mergeSort(arr,s,mid,cnt);
        mergeSort(arr,mid+1,e,cnt);
        // cout<<s<<" "<<e<<" "<<mid<<" "<<cnt<<endl;
        merge(arr,s,e,cnt);
        // prlong long(arr);
    }
    int reversePairs(vector<int>& nums) {
        long long cnt=0;
        mergeSort(nums,0,nums.size()-1,cnt);
        return cnt;

    }
};