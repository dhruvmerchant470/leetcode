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

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s) {
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
    
    bool search(string s) {
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
    
    bool startsWith(string s) {
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */