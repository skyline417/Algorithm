/*
题意：有序数组去重
思路：双指针，一个指针i全部扫一遍，一个指针k，当i遇到不重复的，就将它的值赋给k，然后k++
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();++i)
            if(!i || nums[i]!=nums[i-1]) nums[k++]=nums[i];
        return k;
    }
};