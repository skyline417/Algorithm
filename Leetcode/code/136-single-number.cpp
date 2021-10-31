/*
题意：
    一个整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
思路：
    异或
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto e:nums) ans^=e;
        return ans;
    }
};