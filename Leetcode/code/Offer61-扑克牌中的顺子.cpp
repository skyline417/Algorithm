/*
题意：判断5张牌是不是顺子，0可以看成任意数字
思路：简单模拟
    1、排序，
    2、统计0的个数，
    3、遍历，若相邻两数不连续，用0填充，最后看0够不够
*/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=0;
        while(!nums[k]) ++k;
        for(int i=k+1;i<nums.size();++i){
            if(nums[i]==nums[i-1]) return false;
            k-=(nums[i]-nums[i-1]-1);
        }
        return k>=0;
    }
};