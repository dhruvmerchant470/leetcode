class Solution {
public:
    double angleClock(int hour, int minutes) {
        double t = abs(11/2.0*minutes-30.0*hour);
        // cout<<t<<endl;
        return min(t,abs(360-t));
    }
};