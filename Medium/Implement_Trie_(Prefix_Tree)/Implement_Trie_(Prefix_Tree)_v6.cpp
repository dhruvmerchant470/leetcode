struct node{
    bool isTerminal;
    node* children[26];
    node(){
        isTerminal=false;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};
class Trie {
private:
    node* root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->children[word[i]-'a']==NULL){
                tmp->children[word[i]-'a']=new node();
            }
            tmp=tmp->children[word[i]-'a'];
        }
        tmp->isTerminal=true;
    }
    
    bool search(string word) {
        node* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->children[word[i]-'a']==NULL){
                return false;
            }
            tmp=tmp->children[word[i]-'a'];
        }
        return tmp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        node* tmp=root;
        for(int i=0;i<prefix.size();i++){
            if(tmp->children[prefix[i]-'a']==NULL){
                return false;
            }
            tmp=tmp->children[prefix[i]-'a'];
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