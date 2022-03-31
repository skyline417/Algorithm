/*
题意：斐波那契数
思路：见代码
*/
class Solution {
public:
    int fib(int n) {
        int f[2]={0,1},p=1e9+7;
        for(int i=2;i<=n;++i) f[i%2]=(f[0]+f[1])%p;
        return f[n%2];
    }
};