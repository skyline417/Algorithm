/*
题意：
    买卖股票的最佳时机 一只股票各天的价值 买卖多次（任何时刻手里只能有一支股） 问最大价值
思路：
    贪心 统计所有上升的差
*/ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=0;i<prices.size();++i){
            int st=prices[i];
            while(i+1<prices.size() && prices[i] < prices[i+1]) ++i;
            res+=prices[i]-st;
        }
        return res;
    }
};