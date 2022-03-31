/*
题意：在排序数组中查找元素的第一个和最后一个位置
思路：两次二分
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        int l=0, r=nums.size()-1, L,R;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]>=target){ //注意 >= 是找L 以及r=mid-1
                L=mid;
                r=mid-1;
            }else l=mid+1;
        }
        l=0, r=nums.size()-1;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]<=target){
                R=mid;
                l=mid+1;
            }else r=mid-1;
        }
        if(nums[L]!=target) return 0;
        return R-L+1;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (l <= r) return {l, r};
        else return {-1, -1};
    }
};

