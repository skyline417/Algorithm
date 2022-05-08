/*
题意：掷n个骰子 有n个向上的面 求每一种和出现的概率
思路：每一种和出现的概率 = 每种和的情况数/总情况数
    f[n][s] 表示 掷n个骰子，和为s的情况数
    初始化 f[0][0]=1
    递推公式：f[i][j]=f[i-1][j-k] k=1..6 
*/
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> f(n + 1, vector<int>(6 * n + 1, 0));
        f[0][0] = 1; //初始化 f[i][j]：前i个骰子、和为j 的情况数
        for (int i = 1; i <= n; i ++ ) //次数 层数 第1颗骰子~第n颗骰子
            for (int j = 1; j <= i * 6; j ++ ) //总和: 前i个颗骰子总和最多到i*6
                for (int k = 1; k <= 6; k ++ ) //
                    if (j >= k)
                        f[i][j] += f[i - 1][j - k]; //从前一个状态f[i-1][j-k] 转移过来
        int sum=0;
        for(int i=n; i<=6*n; ++i) sum+=f[n][i]; //总情况数：n个骰子 和为6, 7, 8, ... 6*n
        vector<double>res;
        for(int i=n; i<=6*n; ++i) res.push_back(1.0*f[n][i]/sum);
        
        return res;
    }
};