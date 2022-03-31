/*
题意：最长上升子序列
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2505],res=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            dp[i]=1;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]) dp[i]=max(dp[i],dp[j]+1); //注意是咋转移的
            }
            res=max(dp[i],res);
        }
        return res;
    }
};