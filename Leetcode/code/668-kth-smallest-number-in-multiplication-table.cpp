/*
题意：乘法表找到第k小元素
思路：
    乘法表是有序矩阵（每行升序 每列升序） 转化成第378题
    乘法表范围二分答案，check：统计矩阵中<=mid的元素有多少
    如果mid排名是第k位，那么<=mid的个数 应该是>=k的（因为mid后面可能有连续相等的mid）
    或者：如果mid排名是第k位，那么<mid的个数 应该是<k的 （第二种写法）
时间复杂度：O(nlogV)
*/ 
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1, r=900000000, ans=0;
        while(l<=r){
            int mid=(long long) l + r >> 1;
            int cnt=0,j=n;
            //统计<mid的个数 若mid排在第k位 cnt<k
            for(int i=1;i<=m;++i){
                while(j>=1&&i*j>=mid)--j;
                cnt+=j;
            }
            if(cnt<k){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};