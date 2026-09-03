class Solution {
public:
    bool isPalindrome(int x) {
    long int x1=x;
    long int z=x;
    long int count=0,sum=0;
    while(x!=0){
        int rem=x%10;
        x=x/10;
        count++;
    }
    while(x1!=0){
        int rem=x1%10;
        sum+=rem*pow(10,count-1);
        count--;
        x1=x1/10;
    }
    bool a;
    if(sum==z&&z>=0) a=true;
    else a=false;
    return a;
}
};