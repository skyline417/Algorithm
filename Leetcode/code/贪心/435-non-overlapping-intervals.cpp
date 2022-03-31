/*
题意：不相交区间数（最少删去多少个区间 剩下的区间互不相交）
思路：*右*端点从小到大排序 然后循环：
        判断下一个的左端点是否*小于*上一个的右端点
        如果小于 说明相交 就res++
        否则 右端点取新的
        （对比56题）
*/
class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y){
        return x[1]<y[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int res=0;
        if(a.empty()) return res;
        sort(a.begin(), a.end(), cmp);
        int r=a[0][1];
        for(int i=1;i<a.size();++i){
            if(a[i][0]<r) ++res;
            else r=a[i][1];
            
        }
        return res;
    }
};