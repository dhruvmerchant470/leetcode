class Node {
public:
    Node* child[26];
    bool isTerminal;

    Node() {
        isTerminal = false;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* tmp = root;
        for (char c : word) {
            if (tmp->child[c - 'a'] == NULL) {
                tmp->child[c - 'a'] = new Node();
            }
            tmp = tmp->child[c - 'a'];
        }
        tmp->isTerminal = true;
    }

    bool help(string& word, int index, Node* tmp) {
        if (index == word.size()) return tmp->isTerminal;

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (tmp->child[i] && help(word, index + 1, tmp->child[i])) return true;
            }
        } else {
            int idx = word[index] - 'a';
            if (tmp->child[idx]) return help(word, index + 1, tmp->child[idx]);
            else return false;
        }

        return false;
    }

    bool search(string word) {
        return help(word, 0, root);
    }
};