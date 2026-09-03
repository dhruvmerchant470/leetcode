class Node{
    public:
    bool isTerminal;
    vector<Node*>children;
    Node(){
        isTerminal=false;
        for(int i=0;i<26;i++) children.push_back(NULL);
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->children[word[i]-'a']==NULL){
                Node* newNode=new Node();
                tmp->children[word[i]-'a']=newNode;
            }
            tmp=tmp->children[word[i]-'a'];
        }
        tmp->isTerminal=true;
    }
    
    bool search(string word) {
        Node* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->children[word[i]-'a']==NULL){
                return false;
            }
            tmp=tmp->children[word[i]-'a'];
        }
        return tmp->isTerminal;
    }
    
    bool startsWith(string word) {
        Node* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->children[word[i]-'a']==NULL){
                return false;
            }
            tmp=tmp->children[word[i]-'a'];
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