class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        vector<int>ver1,ver2;
        int i=0;
        while(i<n){
            int num=0;
            while(i<n && version1[i]!='.'){
                num=num*10+(version1[i]-'0');
                i++;
            }
            ver1.push_back(num);
            i++;
        }
        i=0;
        while(i<m){
            int num=0;
            while(i<m && version2[i]!='.'){
                num=num*10+(version2[i]-'0');
                i++;
            }
            ver2.push_back(num);
            i++;
        }
        int size1=ver1.size();
        int size2=ver2.size();
        if(size1>size2){
            for(int i=0;i<size1-size2;i++) ver2.push_back(0);
        }
        if(size1<size2){
            for(int i=0;i<size2-size1;i++) ver1.push_back(0);
        }
        for(int i=0;i<ver1.size();i++){
            if(ver1[i]>ver2[i]) return 1;
            else if(ver1[i]<ver2[i]) return -1;
        }
        return 0;
    }
};