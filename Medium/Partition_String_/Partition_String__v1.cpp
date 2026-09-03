class Node{
    public:
    bool isTerminal;
    Node* children[26];
    Node(){
        isTerminal=false;
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(const string &s){
        Node* tmp=root;
        for(auto ch: s){
            if(tmp->children[ch-'a']==nullptr) tmp->children[ch-'a']=new Node();
            tmp=tmp->children[ch-'a'];
        }
        tmp->isTerminal=true;
    }
    bool search(const string &s){
        Node* tmp=root;
        for(auto ch: s){
            if(tmp->children[ch-'a']==nullptr) return false;
            tmp=tmp->children[ch-'a'];
        }
        return tmp->isTerminal;
    }
};
class Solution {
public:
    vector<string> partitionString(string s) {
        Trie *t=new Trie();
        vector<string>res;
        string tmp="";
        for(int i=0;i<s.size();i++){
            tmp+=s[i];
            if(!t->search(tmp)) {
                t->insert(tmp);
                res.push_back(tmp);
                tmp="";
            }
        }
        return res;
    }
};