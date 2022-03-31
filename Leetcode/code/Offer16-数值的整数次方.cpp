/*
题意：数值的整数次方
思路：指数有负数 要判断（取倒数）；指数很大，要快速幂
*/
class Solution {
public:
    double myPow(double x, int n) {
        typedef long long ll;
        bool flag=n<0;
        double res=1;
        //下面是快速幂
        for(ll k=abs(ll(n));k;k>>=1){ //n如果是INT_MIN，直接取绝对值会溢出
            if(k&1) res*=x;
            x=x*x;
        }
        if(flag) return 1/res;
        else return res;
    }
};