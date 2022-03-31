/*
题意：买卖股票的最佳时机 一只股票各天的价值 买卖一次 问最大价值
思路：贪心？遍历 以当前值减当前最小值 取最大
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minn=1e5;
        int res=0;
        for(int i=0;i<n;++i){
            minn=min(minn,prices[i]);
            res=max(res,prices[i]-minn);
        }
        return res;
    }
};