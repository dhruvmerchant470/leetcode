class Solution {
public:
    void help(vector<int>& m, int k, bool even) {
        if (even) {
            for (int i = 0; i < k; i++) {
                int t = m[0];
                int j = 0;
                for (; j < m.size() - 1; j++) {
                    m[j] = m[j + 1];
                }
                m[j] = t;
            }
        } else {
            for (int i = 0; i < k; i++) {
                int t = m[m.size() - 1];
                int j = m.size() - 1;
                for (; j > 0; j--) {
                    m[j] = m[j - 1];
                }
                m[j] = t;
            }
        }
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int col = mat[0].size();
        k = k % col;
        vector<vector<int>> mat2 = mat;
        int row = mat.size();
        for (int i = 0; i < row; i++) {
            if (i & 1)
                help(mat[i], k, false);
            else
                help(mat[i], k, true);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] != mat2[i][j])
                    return false;
            }
        }
        return true;
    }
};