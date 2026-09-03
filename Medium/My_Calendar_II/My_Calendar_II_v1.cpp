struct cmp {
    bool operator()(const std::pair<int,int>& a, const std::pair<int,int>& b) const {
        return a.second > b.second;  // Sort by string length
    }
};
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
class MyCalendarTwo {
public:
    multiset<pair<int,int>>cal;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        fastIO();
        cal.insert({startTime,1});
        cal.insert({endTime,-1});
        int sum=0;
        for(auto i=cal.begin();i!=cal.end();i++){
            sum+= (*i).second;
            if(sum==3) {
                auto it=cal.find({startTime,1});
                auto it1=cal.find({endTime,-1});
                cal.erase(it);
                cal.erase(it1);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */