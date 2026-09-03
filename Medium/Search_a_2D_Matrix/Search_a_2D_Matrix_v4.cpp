class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int n=matrix[0].size(),m=matrix.size();
        int e=n*m-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int elt=matrix[mid/n][mid%n];
            if(elt==target) return true;
            if(elt>target) e=mid-1;
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return false;
    }
};