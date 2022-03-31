/*
题意：用箭射气球 气球有宽度 最少用多少支箭可以把气球全设炸 也即 算 重叠在一起的 区间的数量
思路：类似435 当前区间左端点大于上一个r时 开始新的一段
*/
class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y){
        return x[1]<y[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;

        sort(points.begin(), points.end(), cmp);
        int r=points[0][1];

        int res=1;
        for(int i=1;i<points.size();++i) if(points[i][0]>r) ++res, r=points[i][1]; 

        return res;
    }
};