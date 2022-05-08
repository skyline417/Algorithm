/*
题意：1~n中数字1的个数 同offer43
思路：https://www.cnblogs.com/xuanxufeng/p/6854105.html
*/
class Solution {
public:
    int countDigitOne(int n) {
        int cnt=0;
        for(long i=1;i<=n;i*=10){
            int a=n/i, b=n%i;
            cnt+= (a+8)/10 * i + (a%10==1?b+1:0);
        }
        return cnt;
    }
};
/*
20220316
*/