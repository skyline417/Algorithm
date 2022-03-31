/*
题意：给定一只股票每天的价格 只能买卖一次，问最大收益
思路：贪心？ 从前往后遍历 记录最小值和最大收益
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j=INT_MAX,res=0;
        for(int i=0;i<prices.size();++i){
            res=max(res,prices[i]-j);
            j=min(j,prices[i]);
        }
        return res;
    }
};