class Node{
public: 
    Node* bit[2];
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int i_bit= num>>i & 1;
            if(!node->bit[i_bit]){
                Node* tmp=new Node();
                node->bit[i_bit]=tmp;
            }
            node=node->bit[i_bit];
        }
    }

    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int i_bit= num>>i & 1;
            if(node->bit[1-i_bit]){
                maxNum = maxNum | 1<<i;
                node=node->bit[1-i_bit];
            }
            else{
                node=node->bit[i_bit];
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t1= new Trie();
        for(auto &it: nums) t1->insert(it);
        int maxi=0;
        for(auto &it:nums){
            maxi=max(maxi,t1->getMax(it));
        }
        return maxi;
    }
};