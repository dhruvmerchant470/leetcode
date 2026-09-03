class TrieNode{
    public: 
    TrieNode* child[26];
    bool isTerminal ;
    TrieNode(){
        isTerminal = false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i=0;i<word.size();i++){
            int t = word[i]-'a';
            // cout<<t<<endl;
            // cout<<word<<endl;
            if(tmp->child[t]==NULL){
                TrieNode* tmp1 = new TrieNode();
                tmp->child[t]=tmp1;
            }
            tmp = tmp->child[t];
        }

        tmp->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* tmp = root;
        for(int i=0;i<word.size();i++){
            int t = word[i]-'a';
            if(tmp->child[t]==NULL){
               return false;
            }
            tmp = tmp->child[t];
        }

        return tmp->isTerminal;
    }
    
    bool startsWith(string word) {
        TrieNode* tmp = root;
        for(int i=0;i<word.size();i++){
            int t = word[i]-'a';
            if(tmp->child[t]==NULL){
                return false;
            }
            tmp = tmp->child[t];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */