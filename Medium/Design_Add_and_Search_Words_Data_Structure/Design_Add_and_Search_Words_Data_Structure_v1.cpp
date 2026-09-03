class Node{
    public:
    Node* child[26];
    bool isTerminal;
    Node(){
        isTerminal=false;
        for(int i=0;i<26;i++) child[i]=NULL;
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
        Node* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->child[word[i]-'a']==NULL){
                tmp->child[word[i]-'a']=new Node();
            }
            tmp=tmp->child[word[i]-'a'];
        }
        tmp->isTerminal=true;
    }
    bool help(string word,int index,Node* tmp){
        if(index==word.size()) return tmp->isTerminal;
        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(tmp->child[i]){
                    if(help(word,index+1,tmp->child[i])) return true;
                }
            }
        }
        else{
            if(tmp->child[word[index]-'a']) return help(word,index+1,tmp->child[word[index]-'a']);
            else return false;
        }
        return false;
    }
    bool search(string word) {
        return help(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */