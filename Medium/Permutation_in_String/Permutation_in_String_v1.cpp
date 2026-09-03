class Solution {
private:
bool areEqual(int arr[],int arr1[])
{
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=arr1[i]) return false;
    }
    return true;
}
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            int number=s1[i]-'a';
            count1[number]++;
        }
        int wSize=s1.length();
        int i=0;
        int count2[26]={0};
        while(i<wSize && i<s2.length())
        {
            int number=s2[i]-'a';
            count2[number]++;
            i++;
        }
        if(areEqual(count1,count2))
        {
            return true;
        }
        while(i<s2.length())
        {
            char newChar=s2[i];
            int index=newChar-'a';
            count2[index]++;

            char oldChar=s2[i-wSize];
            int index1=oldChar-'a';
            count2[index1]--;
            i++;
        if(areEqual(count1,count2)) return true;
        }
        return false;


    }
};