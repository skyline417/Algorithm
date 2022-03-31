/*
题意：分糖果，满足下面两个条件：
    1 每个孩子至少1个 
    2 相邻两个孩子 评分高的得到的糖果比评分低的多
思路：倒两遍
    注意第二遍的时候取最大值
    哎我也不知道咋想出来的也不知道咋证明
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int minn=1, res=0, n=ratings.size();
        vector<int>a(n,1);
        for(int i=1;i<n;++i) if(ratings[i]>ratings[i-1]) a[i]=a[i-1]+1;
        for(int i=n-1;i>0;--i){
            if(ratings[i-1]>ratings[i]) a[i-1]=max(a[i-1],a[i]+1);
            res+=a[i];
        }
        res+=a[0];
        return res;
    }
};