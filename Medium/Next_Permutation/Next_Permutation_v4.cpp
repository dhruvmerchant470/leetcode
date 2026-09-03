class Solution {
public:
    void nextPermutation(vector<int>& a) {
        //step1: find larget index i such that a[i]<a[i+1]
        int index=-1;
        int n=a.size();
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1) {
            reverse(a.begin(),a.end());
            return;
        }

        //step2: now swap a[index] with the smallest element which is larger than a[index] and comes after index
        for(int i=n-1;i>index;i--) {
            if(a[i]>a[index]){
                swap(a[i],a[index]);
                break;
            }
        }

        //step3: reverse the array from index to end;
        reverse(a.begin()+index+1,a.end());
    }
};