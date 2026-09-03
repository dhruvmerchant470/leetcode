class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m = matrix[0].size();
        int s=0,e = n*m-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int row = mid/m;
            int col = mid%m;
            cout<<s<<" "<<e<<" "<<mid<<endl;
            cout<<row<<" "<<col<<endl;
            int tmp = matrix[row][col];
            if(tmp==target) return true;
            else if(tmp>target) e=mid-1;
            else s=mid+1;
        }
        return false;
    }
};