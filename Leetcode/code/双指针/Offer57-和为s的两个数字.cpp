/*
题意：递增数组 2sum
思路：双指针，如果nums[i]+nums[j]>target --j, 如果nums[i]+nums[j]<target ++i
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0,j=nums.size()-1;i<j;){
            if(nums[i]+nums[j]>target) --j;
            else if(nums[i]+nums[j]<target) ++i;
            else break;
        }
        return {nums[i],nums[j]};
    }
};