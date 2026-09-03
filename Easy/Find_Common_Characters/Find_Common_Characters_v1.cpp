class Solution {
public:
    void fillChar(int arr[26],string word)
    {
        for(char ch : word)
        {
            arr[ch-'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int count[26];
        fillChar(count,words[0]);
        for(int i=1;i<words.size();i++)
        {
            int temp[26]={0};
            fillChar(temp,words[i]);
            for(int j=0;j<26;j++)
            {
                count[j]=min(count[j],temp[j]);
                
            }
        }
        for(int i=0;i<26;i++)
        {
            while(count[i]--)
            {
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};