class Solution {
public:
    /*
    APPROACH: BINARY SEARCH
    1. WE CHECK IF THE PREVIOUS AND THE NEXT ELEMENT ARE GREATER THAN THE
    CURRENT ELEMENT THEN CURRENT ELEMENT IS THE ANSWER
    2. ELSE, WE CHECK IF THE PREVIOUS ELEMENT IS
    */
    int findMin(vector<int>& arr) {
        if (arr.size() == 1)
            return arr[0];
        // if(arr.size()==2) return min(arr[0],arr[1]);
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e) {
            cout<<s<<" "<<e<<endl;
            int mid = (s + e) / 2;
            if ((mid == 0 && arr[mid] < arr[mid + 1]) ||
                (mid == e && arr[mid] < arr[mid - 1]) ||
                (mid!=0 && mid!=e && arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])) {
                return arr[mid];
            }
            if (arr[mid] >= arr[0] &&
                arr[mid] >= arr[e]) {
                s = mid + 1;
            } else
                e = mid - 1;
        }
        
        return -1;
    }
};