class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows=matrix.size(),cols=matrix[0].size(),s=0,e=rows*cols-1,mid=s+(e-s)/2;
    while(s<=e)
    {
        int elt=matrix[mid/cols][mid%cols];
        if(elt==target) return true;
        if(elt>target) {e=mid-1;}
        else {s=mid+1;}
        mid=s+(e-s)/2;
    }
    return false;
}
};