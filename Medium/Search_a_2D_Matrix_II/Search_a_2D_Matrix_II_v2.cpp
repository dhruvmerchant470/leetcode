class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rows=matrix.size(),cols=matrix[0].size(),rIndex=0,cIndex=cols-1;
       while(rIndex<rows&&cIndex>=0)
       {int elt=matrix[rIndex][cIndex];
        if(elt==target) return true;
        if(elt<target) rIndex++;
        else cIndex--;
       }
       return false;
    }
};