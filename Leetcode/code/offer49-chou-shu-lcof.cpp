/*
题意：丑数是指 因子只包括2、3或5的数 求第n个丑数
思路：多路归并。
    三个指针 代表2、3、5的倍数
    首先都指向第1个数：1，然后往后（直接乘2、3、5），
    遇到最小的2的倍数、3的倍数、5的倍数，
    把对应指针移到该数上（可能不止一个指针要移 比如6既是2的倍数也是3的倍数），
    这样往后移n次，就是第n个丑数
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>q;
        q.push_back(1);
        int i=0,j=0,k=0;
        while(--n){
            int t=min(q[i]*2, min(q[j]*3, q[k]*5));
            q.push_back(t);
            if(q[i]*2==t) ++i;
            if(q[j]*3==t) ++j;
            if(q[k]*5==t) ++k;
        }
        return q.back();
    }   
};