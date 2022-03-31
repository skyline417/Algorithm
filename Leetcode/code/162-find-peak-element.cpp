/*
题意：无序数组，找到任意一个峰值
思路：可以用二分：
        若nums[mid]>nums[mid+1]
            峰值一定在左边，要么就是nums[mid]，要么一直推到nums[0]
        否则
            同理，峰值一定在右边
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int l=0, n=nums.size(), r=n-1, ans=0;
        nums.push_back((long long)nums[r]-1);
        while(l<=r){
            int mid=l+r >> 1;
            if(nums[mid]>nums[mid+1]){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};