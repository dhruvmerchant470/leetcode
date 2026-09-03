class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int main_index = nums1.size()-1;
        m--;
        n--;
        while(m>=0 && n>=0){
            if(nums1[m]>nums2[n]){
                nums1[main_index]=nums1[m];
                m--;
            }else{
                nums1[main_index]=nums2[n];
                n--;
            }
            main_index--;
        }
        while(n>=0){
            nums1[main_index]=nums2[n];
            n--;
            main_index--;
        }
    }
};