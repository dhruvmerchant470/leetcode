// we will use seg trees
class Solution {
public:
    class SegmentTreeNode {
        public:
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        int sum;
        int start_index;
        int end_index;

        public:
        SegmentTreeNode(int start,int end){
            start_index=start;
            end_index=end;
            sum=0;
            left=NULL;
            right=NULL;
        }
    };

        SegmentTreeNode* buildTree(int start, int end){
            if(start>end){
                return NULL;
            }
            else{
                SegmentTreeNode* tmp=new SegmentTreeNode(start,end);
                if(start==end) return tmp;
                else{
                    int mid=start+(end-start)/2;
                    tmp->left=buildTree(start,mid);
                    tmp->right=buildTree(mid+1,end);
                }
                return tmp;
            }
        }

        void update(int index, SegmentTreeNode* root){
            if(root==NULL) return;

            if(root->start_index==index && root->end_index==index){
                root->sum+=1;
            }
            else{
                int mid=root->start_index+(root->end_index-root->start_index)/2;
                if(mid>=index) update(index,root->left);
                else update(index,root->right);
                root->sum=root->left->sum+root->right->sum;
            }
        }

        int sumRange(SegmentTreeNode* root,int start, int end){
            if(root==NULL||start>end) return 0;

            if(root->start_index==start && root->end_index==end) return root->sum;
            else{
                int mid=root->start_index+(root->end_index-root->start_index)/2;
                if(mid>=end) return sumRange(root->left,start,end);
                else if(start>mid) return sumRange(root->right,start,end);
                else return sumRange(root->left,start,mid)+sumRange(root->right,mid+1,end); 
            }
        }
    
        vector<int> countSmaller(vector<int>& nums) {
            vector<int>ans(nums.size());
            if(nums.size()==0) return ans;
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int i=0;i<nums.size();i++){
                mini=min(mini,nums[i]);
                maxi=max(maxi,nums[i]);
            }
            SegmentTreeNode* root=buildTree(mini,maxi);
            for(int i=nums.size()-1;i>=0;i--){
                update(nums[i],root);
                ans[i]=sumRange(root,mini,nums[i]-1);
            }
            return ans;
        }
};