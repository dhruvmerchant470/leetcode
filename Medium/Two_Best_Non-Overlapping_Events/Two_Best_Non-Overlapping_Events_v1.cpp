class Solution {
public:
    int bs(vector<vector<int>>&events,int end,int index,vector<int>&suffix){
        int low = index;
        int high = events.size()-1;
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(events[mid][0]>end){
                // cout<<"hello"<<endl;
                ans = max(ans,suffix[mid]);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int size = events.size();
        sort(events.begin(),events.end());
        // for(int i=0;i<events.size();i++){
        //     cout<<events[i][0]<<" "<<events[i][1]<<" "<<events[i][2]<<endl;
        // }
        vector<int>suffix(size,0);
        suffix[size-1]=events[size-1][2];
        for(int i=size-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],events[i][2]);
        }
        int ans=0;
        for(int i=0;i<size;i++){
            int tmp = bs(events,events[i][1],i+1,suffix);
            // cout<<tmp<<endl;
            // cout<<events[i][2]<<endl;
            ans=max(events[i][2]+tmp,ans);
        }
        return ans;
    }
};