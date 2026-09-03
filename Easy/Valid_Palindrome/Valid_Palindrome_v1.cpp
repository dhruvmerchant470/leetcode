class Solution {
public:
    char tolower(char n)
{
    if(n>='a'&&n<='z') return n;
    else  return n-'A'+'a';
    
}
    bool isPalindrome(string s) {
         int st=0,e=s.length()-1;
   while(st<e)
   {
       if(isalnum(s[st])&&isalnum(s[e]))
       {
         if (tolower(s[st]) == tolower(s[e])) {
           st++;
           e--;
         }
         else{
             return false;
         }
       }
       else if(!isalnum(s[st])) st++;
       else if(!isalnum(s[e])) e--;
       else return false;
   }
    return true;
    }
};