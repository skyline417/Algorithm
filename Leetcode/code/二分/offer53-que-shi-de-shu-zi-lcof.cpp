/*
题意：长为n的有序数组，0~n一共n+1个数填进n个空位 找出缺失的数字
思路：
    有序数组 缺失数字前 nums[i]=i 缺失数字后 nums[i]!=i(nums[i]=i+1) 
    二分
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0, r=nums.size()-1,ans=0;
        while(l<=r){
            int mid = l + r >> 1;
            if(nums[mid]==mid){ //注意
                ans=mid;
                l=mid+1; //注意
            }else{
                r=mid-1;
            }
        }
        if(ans==nums[ans]) ++ans; //如果0~n-1所有数字都满足nums[i]==i 那么缺失的数是n
        return ans;
    }
};