/*
题意：
判断数组中有没有132序列(ijk)
思路：
线性预处理前缀最小值(i)，单调栈预处理每个数(k)左边第一个大于它的数(j)，枚举第三个数(k),看有没有132这样的序列
性质：只要答案存在，对于枚举的第3个数，已确定的(i,j)一定是最优的，即便不满足条件, 比如 5 7 2的2，这个2总是可以被它右边另一个数（正确答案）替换

*/
class Solution {
public:
    static const int N=2e5+5, INF=0x3f3f3f3f;
    int tt=0,stk[N],a1[N],a2[N];
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        
        a1[0]=nums[0];
        for(int i=0;i<n;++i){
            //前缀最小值
            if(i) a1[i]=min(a1[i-1],nums[i]);

            //单调栈：左边第一个大于它的数index
            while(tt&&nums[stk[tt]]<=nums[i]) tt--; 
            if(tt) a2[i]=stk[tt]; else a2[i]=INF;
            stk[++tt]=i;
            
            //枚举a3
            if(a2[i]==INF||a2[i]==0) continue;
            int mid=nums[a2[i]],left=a1[a2[i]-1];
            if(left<nums[i]&&nums[i]<mid) return 1;
        }

        return 0;
    }
};