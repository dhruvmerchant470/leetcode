class Solution {
public:
    bool bSearch(vector<int>arr,int target)
    {
        long long int s=0,e=arr.size()-1,mid=s+(e-s)/2;
        while(s<=e)
        {
            if(arr[mid]==target) return true;
            if(arr[mid]>target) e=mid-1;
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       long long  int row=matrix.size();
        for(long long int i=0;i<row;i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};