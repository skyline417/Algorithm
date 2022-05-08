/*
题意：数组中只有一个数出现一次，其余数都出现了三次，找出这个数、
思路：数电模3
    参考：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/ 评论区
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b=0;
        for(int i:nums){
            a = ~b & (a^i);
            b = ~a & (b^i);
        }
        return a;
    }
};