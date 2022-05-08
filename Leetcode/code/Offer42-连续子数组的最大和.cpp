/*
题意：最大子段和
思路：任意最大子段和 和>0 所以发现<0就可以重新开始了
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0, maxn=-1e8;
        for(int i=0; i<nums.size(); ++i){
            cur+=nums[i];
            maxn=max(cur,maxn);
            cur=max(0,cur);
        }
        return maxn;
    }
};