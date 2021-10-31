
/*
题意：
    一个整数数组，其中两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素。
思路：
    常数空间复杂度
    先求异或和 找出a^b的值
    然后找出(a^b)的任意一个为1的位 第k位为1
    根据这一位 把数组分成两部分 a和b各属于一部分
    每一部分 可以化简为这个问题：一个整数数组，其中某个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那个元素。
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab=0;
        for(auto e:nums) ab^=e;
        int k=0;
        while(!(ab>>k&1)) ++k;
        vector<int>ans(2);
        for(auto e:nums){
            if(!(e>>k&1)) ans[0]^=e;
            else ans[1]^=e;
        }
        return ans;
    }
};