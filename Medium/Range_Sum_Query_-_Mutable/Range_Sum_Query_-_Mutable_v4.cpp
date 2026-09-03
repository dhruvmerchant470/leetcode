class NumArray {
public:
    vector<int>tmp;
    int *seg;
    int n;
    NumArray(vector<int>& nums) {
        tmp=nums;
        n=nums.size();
        seg=new int[4*n];
        buildseg(0,n-1,0);
    }
    void update_help(int index,int left,int right, int val, int i){
        if(left==right) {
            seg[i]=val;
            return;
        }
        int mid=(left+right)/2;
        if(index<=mid) update_help(index,left,mid,val,2*i+1);
        else update_help(index,mid+1,right,val,2*i+2);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    void update(int index, int val) {
        tmp[index]=val;
        update_help(index,0,n-1,val,0);
        // print();
    }
    void buildseg(int left, int right, int index){
        if(left==right) {
            seg[index]=tmp[left];
            return;
        }
        int mid=(left+right)/2;
        buildseg(left,mid,2*index+1);
        buildseg(mid+1,right,2*index+2);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    int query(int left, int right, int start, int end, int index){
        if(left>end || right<start){
            return 0;
        }
        else if(left>=start&&right<=end) return seg[index];
        else {
            int mid=(left+right)/2;
            return query(left,mid,start,end,2*index+1)+query(mid+1,right,start,end,2*index+2);
        }
    }
    void print(){
        for(int i=0;i<4*n;i++) cout<<seg[i]<<" ";
        cout<<endl;
    }
    int sumRange(int left, int right) {
        
        return query(0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */