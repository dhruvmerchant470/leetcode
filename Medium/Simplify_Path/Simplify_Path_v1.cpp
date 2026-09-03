class Solution {
public:
    string simplifyPath(string path) {
        stack<char> s;
        int dot_count = 0;
        bool flag=0;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                flag=1;
                if (!s.empty() && s.top() == '/') {
                    continue;
                } else if (dot_count != 2 && dot_count != 1) {
                    dot_count = 0;
                    s.push(path[i]);
                } else {
                    if (dot_count == 1) {
                        while (s.top() != '/')
                            s.pop();
                    }
                    if (dot_count == 2) {
                        int size = 0;
                        while (!s.empty() && size != 2) {
                            if (s.top() == '/')
                                size++;
                            s.pop();
                        }
                        s.push('/');
                    }
                    dot_count = 0;
                }
            } else {
                if (flag && !s.empty() && (s.top() == '.' || s.top() == '/') &&
                    path[i] == '.')
                    dot_count++;
                else
                    {
                        dot_count = 0;
                        flag=0;
                    }
                s.push(path[i]);
            }
        }
        if (dot_count == 2) {
            int size = 0;
            while (!s.empty() && size != 2) {
                if (s.top() == '/')
                    size++;
                s.pop();
            }
            s.push('/');
        }
        if (dot_count == 1) {
            while (s.top() != '/')
                s.pop();
        }
        string ans = "";
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        if (ans.size() > 1 && ans[ans.size() - 1] == '/')
            ans.pop_back();
        return ans;
    }
};