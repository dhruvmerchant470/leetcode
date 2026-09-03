class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int sCol=0,eCol=cols-1,sRow=0,eRow=rows-1;
        int total=rows*cols;
        vector<int>ans;
        int count=0;
        while(count<total)
        {
            for(int i=sCol;i<=eCol;i++)
            {
                ans.push_back(matrix[sRow][i]);
                count++;
            }
            sRow++;
            if(count>=total) break;
            for(int i=sRow;i<=eRow;i++)
            {
                ans.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;
            if(count>=total) break;
            for(int i=eCol;i>=sCol;i--)
            {
                ans.push_back(matrix[eRow][i]);
                count++;
            }
            eRow--;
            if(count>=total) break;
            for(int i=eRow;i>=sRow;i--)
            {
                ans.push_back(matrix[i][sCol]);
                count++;
            }
            sCol++;
            if(count>=total) break;
        }
    return ans;
        }


    
};