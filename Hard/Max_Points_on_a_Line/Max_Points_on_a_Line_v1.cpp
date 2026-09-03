class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            map<double, int> mp;
            for (int j = i + 1; j < n; j++) {
                double slope;
                if ((points[j][0] - points[i][0]) != 0)
                    slope = 1.0 * (points[j][1] - points[i][1]) /
                            (points[j][0] - points[i][0]);
                else
                    slope = INT_MAX;
                mp[slope] += 1;
                maxi = max(maxi, mp[slope]);
            }
        }
        return maxi + 1;
    }
};