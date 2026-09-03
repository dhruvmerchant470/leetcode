class Solution {
public:
    int find(int mid,vector<vector<int>>& matrix){
        int n=matrix.size();
        int row=0,col=n-1;
        int cnt=0;
        while(row<n&&col>=0){
            if(matrix[row][col]<=mid){
                cnt+=(col+1);
                row++;
            }
            else{
                col--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int start=matrix[0][0];
        int n=matrix[0].size();
        int end=matrix[n-1][n-1];
        int mid=(start+end)/2;
        while(start<=end){
            if(find(mid,matrix)<k){
                start=mid+1;
            }
            else{
                end=mid-1;                
            }
            mid=(start+end)/2;
        }
        return start;
    }
};