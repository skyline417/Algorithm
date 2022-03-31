/*
题意：剪绳子（>1段） 使各段乘积最大
思路：最优：3 
*/
class Solution {
public:
    int cuttingRope(int n) {
        int p=1e9+7;
        long long res=1;
        if(n<4) return n-1;
        
        while(n>4){
            res=res*3%p;
            n-=3;
        }
        return res*n%p;
        
    }
};