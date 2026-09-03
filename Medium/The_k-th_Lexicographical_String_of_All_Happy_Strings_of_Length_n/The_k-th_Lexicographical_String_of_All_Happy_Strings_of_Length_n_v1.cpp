class Solution {
public:
    vector<string>s1;
    void generate(int n,string s,int index){
        // if(index==n) return;
        if(index==n-1) {
            s1.push_back(s);
            return;
        }
        if(s[index]=='a'){
            generate(n,s+"b",index+1);
            generate(n,s+"c",index+1);
        }
        else if(s[index]=='b'){
            generate(n,s+"a",index+1);
            generate(n,s+"c",index+1);
        }
        else if(s[index]=='c'){
            generate(n,s+"a",index+1);
            generate(n,s+"b",index+1);
        }
    }
    string getHappyString(int n, int k) {
        if(n==0) return "";
        generate(n,"a",0);
        generate(n,"b",0);
        generate(n,"c",0);
        // sort(s1.begin(),s1.end());
        sort(s1.begin(),s1.end());
        for(int i=0;i<s1.size();i++){
            cout<<s1[i]<<endl;
        }
        if(k>s1.size()) return "";
        return s1[k-1];
    }
};