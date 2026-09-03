class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(TrieNode* root, string s) {

        TrieNode* child = root;
        for (char c : s) {
            int index = c - 'a';
            if (child->children[index] != NULL)
                child = child->children[index];
            else {
                TrieNode* child1 = new TrieNode();
                child->children[index] = child1;
                child = child1;
            }
        }
        child->isTerminal = true;
    }

    bool search(TrieNode* root, string s) {
        TrieNode* child = root;
        for (char c : s) {
            int index = c - 'a';
            if (child->children[index] != NULL)
                child = child->children[index];
            else {
                return false;
            }
        }
        return child->isTerminal;
    }
    pair<bool, pair<int, int>> no_of_child(TrieNode* root) {
        int cnt = 0;
        int index;
        pair<bool, pair<int, int>> ans,ans1;
        bool flag = 0;
        for (int i = 25; i >= 0; i--) {
            if (root->children[i] != NULL) {
                cnt++;
                index = i;
                if (!flag) {
                    if (root->children[i]->isTerminal) {
                        ans = {true, {index, cnt}};
                        flag = 1;
                    }
                }
            }
        }
        ans1.first=ans.first;
        ans1.second={index,cnt};
        return ans1;
    }
    bool prefixSearch(TrieNode* root, string s) {
        TrieNode* child = root;
        int cnt = 0;
        for (char c : s) {
            int index = c - 'a';
            if (child->children[index] != NULL)
                child = child->children[index];
            else {
                return false;
            }
            cnt++;
        }
        if (cnt == s.size())
            return true;
        return child->isTerminal;
    }

    string pre(TrieNode* root) {
        string ans = "";
        TrieNode* child = root;
        cout << no_of_child(child).second.second << endl;
        while (no_of_child(child).second.second == 1 &&
               no_of_child(child).first == false) {
            ans += (no_of_child(child).second.first + 'a');
            child = child->children[no_of_child(child).second.first];
        }
        if (no_of_child(child).first && no_of_child(child).second.second == 1)
            ans += (no_of_child(child).second.first + 'a');

        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t1;
        for (int i = 0; i < strs.size(); i++) {
            t1.insert(t1.root, strs[i]);
            if (strs[i] == "")
                return "";
        }
        return t1.pre(t1.root);
    }
};