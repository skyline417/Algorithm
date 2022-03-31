/*
题意：找有序数组中的单一元素
思路：两两一组，单一元素位于第一个不相等的二元组处，使用二分来查找。
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        nums.push_back(-1);
        int l=0,r=nums.size()/2-1,ans;
        while(l<=r){
            int mid=(l+r)>>1;
            if(nums[mid*2]==nums[mid*2+1]) l=mid+1;
            else r=mid-1;
        }
        return nums[l*2];
    }
};