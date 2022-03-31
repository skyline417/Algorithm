/*
题意：接雨水
思路：第一次从左往右扫描 保存前缀最大值
    第二次从右往左扫描 保存后缀最大值
    第三次统计答案 每个位置存的水=min(lmax[i],rmax[i])-height[i]
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), res=0, lmax[20005]={0}, rmax[20005]={0};
        lmax[0]=height[0], rmax[n-1]=height[n-1];
        for(int i=1;    i<n; ++i) lmax[i]=max(lmax[i-1],height[i]);
        for(int i=n-2; i>=0; --i) rmax[i]=max(rmax[i+1],height[i]);
        for(int i=1; i<n-1; ++i) res+=min(rmax[i],lmax[i])-height[i];
        return res;
    }
};
/*
20220329 忘了做法
*/