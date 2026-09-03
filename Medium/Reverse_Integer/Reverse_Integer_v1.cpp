class Solution {
public:
    int reverse(int x) {
    if(x>=-2147483647 && x<1500000000){
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
    if(sum>-2147483648 && sum<2147483647)
    return sum;
    else
    return 0;}
    else {return 0;}
    }
};