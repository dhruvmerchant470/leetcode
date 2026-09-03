class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                s.push(asteroids[i]);
            } else {
                if (asteroids[i] * s.top() > 0)
                    s.push(asteroids[i]);
                else {
                    if (asteroids[i] < 0) {
                        bool flag = 1;
                        while (!s.empty() && asteroids[i] * s.top() < 0 &&
                               abs(asteroids[i]) >= s.top() && flag) {
                            if (abs(s.top()) == abs(asteroids[i]))
                                flag = 0;
                            s.pop();
                        }
                        if (!s.empty() && asteroids[i] * s.top() > 0 && flag)
                            s.push(asteroids[i]);
                        if (s.empty() && flag)
                            s.push(asteroids[i]);
                    } else {
                        s.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};