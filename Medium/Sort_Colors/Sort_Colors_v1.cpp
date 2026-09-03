class Solution {
public:
    void sortColors(vector<int>& arr) {
        //dutch flag algo
        //low is for 0
        //mid id for one
        //high is for 2
        //cases only for nums[mid]
        int l=0,m=0,h=arr.size()-1;
        while(m<=h){
            if(arr[m]==0){
                swap(arr[m],arr[l]);
                l++;
                m++;
            }
            else if(arr[m]==1){
                m++;
            }
            else if(arr[m]==2){
                swap(arr[m],arr[h]);
                h--;
            }
        }
    }
};