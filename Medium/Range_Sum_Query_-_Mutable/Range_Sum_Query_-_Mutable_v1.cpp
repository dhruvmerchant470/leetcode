class NumArray {
public:

    class SegmentTreeNode{
        public:
        SegmentTreeNode* left,*right;
        int sum;
        int start_index,end_index;

        //constructor
        SegmentTreeNode(int start,int end){
            start_index=start;
            end_index=end;
            left=NULL;
            right=NULL;
            sum=0;
        }
    };

    SegmentTreeNode* root=NULL;
    
    SegmentTreeNode* buildTree(int start,int end,vector<int>& nums){
        // cout<<"s: "<<start<<endl;
        if(start>end) return NULL;
        else{
            SegmentTreeNode* tmp=new SegmentTreeNode(start,end);
            if(start==end){
                tmp->sum=nums[start];
            }
            else{
                int mid= start + (end-start)/2;
                tmp->left=buildTree(start,mid,nums);
                tmp->right=buildTree(mid+1,end,nums);
                tmp->sum=tmp->left->sum+tmp->right->sum;
            }
            return tmp;
        }
    }
    NumArray(vector<int>& nums) {
        root=buildTree(0,nums.size()-1,nums);
    }
    
    void updatehelper(SegmentTreeNode* root,int val,int pos){
        if(root->start_index==root->end_index) root->sum=val;
        else{
            int mid= root->start_index+(root->end_index-root->start_index)/2;
            if(pos<=mid) updatehelper(root->left,val,pos);
            else updatehelper(root->right,val,pos);
            root->sum=root->left->sum+root->right->sum;
        }
    }
    void update(int index, int val) {
        updatehelper(root,val,index);
    }
    int sum_helper(SegmentTreeNode* root,int start, int end){
        // cout<<root->sum<<" "<<root->start_index<<" "<<root->end_index<<endl;
        if(root->start_index==start && root->end_index==end) {
            // cout<<"in"<<root->start_index<<" "<<root->end_index<<" "<<cout<<start<<endl;
            return root->sum;
        }
        else{
            int mid=root->start_index+(root->end_index-root->start_index)/2;
            if(end<=mid){
                return sum_helper(root->left,start,end);
            }
            else if(start>mid){
                return sum_helper(root->right,start,end);
            }
            else{
                return sum_helper(root->left,start,mid)+sum_helper(root->right,mid+1,end);
            }
        }
    }
    int sumRange(int left, int right) {
        return sum_helper(root,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */