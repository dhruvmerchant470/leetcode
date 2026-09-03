class Node {
public:
    Node* child[2];
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* tmp = root;
        for(int i=31;i>=0;i--){
            int digi = num>>i & 1 ;
            // cout<<"hi "<<digi<<endl;
            if(!tmp->child[digi]){
                tmp->child[digi] = new Node();
            }
            tmp = tmp->child[digi];
        }
    }

    int getMax(int num){
        Node* tmp = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int digi = num>>i & 1;
            if(tmp->child[1-digi]){
                tmp = tmp->child[1-digi];
                ans = ans | 1<<i;
            }
            else{
                tmp = tmp->child[digi];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        for(auto num : nums) t->insert(num);
        int maxi = -1;
        for(auto num : nums) maxi = max(maxi,t->getMax(num));
        return maxi;
    }
};