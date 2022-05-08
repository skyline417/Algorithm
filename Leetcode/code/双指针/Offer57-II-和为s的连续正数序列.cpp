/*
题意：给定正整数target，输出所有和为target的连续**正**整数序列（至少含有两个数）。
思路：双指针，除去输出时间O(n^2)，算法的时间复杂度是O(n)
    因为是连续正整数序列 所以有单调性 即 i右移(和变小)，j必右移！所以可以用双指针！
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int sum) {
        vector<vector<int>> res;
        for(int i=1, j=1, s=1; i<=sum/2;++i){ //枚举左端点，左端点每次右移1 //当i>sum/2, i + (i+1) 必大于 sum，剪枝
            while(s<sum) ++j, s+=j;//随着左端点右移，右端点必右移
            //右端点总移动次数为O(n)
            if(s==sum && j>i){ 
                //保存答案
                vector<int>line;
                for(int k=i;k<=j;++k) line.push_back(k);
                res.push_back(line);
            }
            s-=i; //下面左端点要右移了
        }
        return res;
    }
};

