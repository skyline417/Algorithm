/*
题意：合并区间（把重叠的合并）
思路：左端点从小到大排序 然后循环：
        判断下一个的左端点是否大于上一个的右端点
        如果大于 就新开一段
        否则 右端点取靠右的
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        if(intervals.empty()) return res;

        sort(intervals.begin(), intervals.end());
        int l=intervals[0][0], r=intervals[0][1];

        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]>r){
                res.push_back({l,r});
                l=intervals[i][0], r=intervals[i][1];
            }else r=max(r, intervals[i][1]);

        }
        res.push_back({l,r});
        return res;
    }
};