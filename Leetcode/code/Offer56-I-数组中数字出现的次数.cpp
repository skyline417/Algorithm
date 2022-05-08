/*
题意：数组中有两个数只出现一次，其余数都出现两次，求这两个数
思路：（0异或任何数都得0）
    如果只有一个数只出现一次，异或即可求得。
    现在有两个数只出现一次，考虑把这个数组分成两个子数组，在每个子数组里 只有一个数只出现一次，转化成上面的简单问题。
    按什么标准划分？
        这两个只出现一次的数，她俩的二进制一定有一位是不一样的，找到这个不一样的一位，假设是第k位，她俩的异或值为1
        其他所有数 第k位为1的分一边，为0的分另一边。
        这样就能转化成那个简单问题了。
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp=0;
        for(auto e:nums) tmp=e^tmp;
        int k=0;
        while(!(tmp>>k&1)) ++k;
        int X=0; //第一个集合
        for(auto e:nums){
            if(e>>k&1) X^=e;
        }
        return {X, X^tmp};
    }
};