/*
题意：信封 长宽二元组 问最多有几个套娃
思路：LIS
*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int dp[5005], res=0;
        int n=a.size();
        for(int i=0;i<n;++i){
            dp[i]=1;
            for(int j=0;j<i;++j) if(a[j][0]<a[i][0]&&a[j][1]<a[i][1]) dp[i]=max(dp[i],dp[j]+1);
            res=max(res,dp[i]);
        }
        return res;
    }
};