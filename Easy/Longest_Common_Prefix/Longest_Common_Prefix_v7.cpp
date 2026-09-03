class Node{
    public:
    Node * child[26];
    bool isTerminal;
    Node(){
        for(int i=0;i<26;i++) child[i]=NULL;
        isTerminal = false;
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* tmp = root;
        for(auto c : s){
            if(tmp->child[c-'a']==NULL){
                tmp->child[c-'a'] = new Node();
            }
            tmp = tmp->child[c-'a'];
        }
        tmp->isTerminal = true;
    }
    pair<int,int> childs(Node* t){
        int cnt = 0;
        int index = -1;
        for(int i=0;i<26;i++){
            if(t->child[i]){
                index = i;
                cnt+=1;
            }
        }
        return {cnt,index};
    }
    string check(){
        Node* tmp = root;
        string ans = "";
        while(true){
            auto ch = childs(tmp);
            if(ch.first==1){
                ans.push_back(('a'+ch.second));
                tmp = tmp->child[ch.second];
                if(tmp->isTerminal) return ans;
            }
            else return ans;
        }
        return "";
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(auto str : strs){
            if(str=="") return str;
            t.insert(str);
        }
        return t.check();
    }
};