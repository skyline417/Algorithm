/*
题意：
    找最小进制k 使十进制n的k进制值为全1
思路：
    k一定存在, n-1就是答案 因为 (n-1)^1+(n-1)^0 == n
    设t为11..1的位数： 11..1 = k^t + k^(t-1) + ... + k^0
    可以证明 k < n^(1/t) < k+1, 
    所以枚举t 从59到2 （最多就这么多位）
        然后先求pow(n, 1/t) （默认下取整） 得到k
        然后判断这个答案(k,t)对不对
*/
class Solution {
public:
    string smallestGoodBase(string N) {
        typedef long long ll;
        ll n=stoll(N);
        ll ans=n-1;
        for(int t=log2(n);t>=2;--t){//从大到小 枚举 1的位数
            ll k=pow(n,1.0/t); //进制
            ll r=1;
            for(int i=0;i<t;++i) r=r*k+1;
            if(r==n) {ans=k;break;}
        }
        return to_string(ans);
    }
};