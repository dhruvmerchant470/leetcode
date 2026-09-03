class Solution {
public:
    long long cnt=0;
    void merge(vector<int>&nums,long long s,long long e){
        long long mid=(s+e)/2;
        long long l1 = mid-s+1;
        long long l2 = e-mid;
        long long a1[l1],a2[l2];
        long long main_index=s;
        for(long long i=0;i<l1;i++,main_index++) a1[i]=nums[main_index];
        for(long long i=0;i<l2;i++,main_index++) a2[i]=nums[main_index];
        long long i=0,j=0;
        main_index=s;
        while(i<l1&&j<l2){
            if(a1[i]>2*a2[j]){
                cnt+=(l1-i);
                j++;
            }
            else{
                i++;
            }
        }
        i=0,j=0;
        while(i<l1&&j<l2){
            if(a1[i]>a2[j]){
                nums[main_index]=a2[j];
                main_index++;
                j++;
            }else{
                nums[main_index]=a1[i];
                i++;
                main_index++;
            }
        }
        while(i<l1){
            nums[main_index++]=a1[i++];
        }
        while(j<l2){
            nums[main_index++]=a2[j++];
        }
    }
    void mergeSort(vector<int>&nums,long long s, long long e){
        if(s>=e) return;
        long long mid = (s+e)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,e);
    }
    long long reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};