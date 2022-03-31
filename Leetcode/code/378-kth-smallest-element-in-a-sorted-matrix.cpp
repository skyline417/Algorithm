/*
题意：有序矩阵（每行升序 每列升序）找到第k小元素
思路：int范围二分答案，check：统计矩阵中<=mid的元素有多少
    如果mid排名是第k位，那么<=mid的个数 应该是>=k的（因为mid后面可能有连续相等的mid）
    或者：如果mid排名是第k位，那么<mid的个数 应该是<k的 （第二种写法）
时间复杂度：O(nlogV)
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=INT_MIN, r=INT_MAX, ans=0; //二分答案 答案是int范围
        while(l<=r){
            int mid = (long long)l + r >> 1;
            //统计 小于等于mid的有多少个
            int j=n-1,cnt=0;
            for(int i=0;i<n;++i){
                while(j>=0 && matrix[i][j]>mid ) --j; //总共扫描次数 j从n-1到0
                cnt+=j+1;
            }
            if(cnt<k){
                l=mid+1;
            }else{
                ans=mid; //注意
                r=mid-1;
            }
        }
        return ans;
    }
};

/*
第二种写法
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=INT_MIN, r=INT_MAX, ans=0; //二分答案 答案是int范围
        while(l<=r){
            int mid = (long long)l + r >> 1;
            //统计 小于mid的有多少个
            int j=n-1,cnt=0;
            for(int i=0;i<n;++i){
                while(j>=0 && matrix[i][j]>=mid ) --j;
                cnt+=j+1;
            }

            if(cnt<k){
                l=mid+1;
                ans=mid; //注意
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};
*/