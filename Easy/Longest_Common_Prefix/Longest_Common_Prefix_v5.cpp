class Node{
    public:
    Node *children[26];
    bool flag;
    int child;
    
    Node(){
        flag=false;
        for(int i=0;i<26;i++) children[i]=NULL;
        child=0;
        
    }
};

class Trie {
  public:
    Node* root;
    Trie() {
        // implement Trie
        root=new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->children[word[i]-'a']){
                Node* tmp=new Node();
                node->children[word[i]-'a']=tmp;
                node->child++;
                
            }
            node=node->children[word[i]-'a'];
            
        }
        node->flag=true;
    }

    bool search(string &word) {
        // search word in the Trie
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->children[word[i]-'a']) return false;
            node=node->children[word[i]-'a'];
        }
        return node->flag;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->children[word[i]-'a']) return false;
            node=node->children[word[i]-'a'];
        }
        return true;
    }

    string solve(){
        string ans="";
        Node* node=root;
        while(node->child==1 && !node->flag){
            for(int i=0;i<26;i++) 
            if(node->children[i]) {
                node=node->children[i];
                ans.push_back('a'+i);
                break;
            }
        }
        return ans;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t=new Trie();
        for(auto str: strs) {
            t->insert(str);
        }
        return t->solve();
    }

};