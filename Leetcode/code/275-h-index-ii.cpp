/*
题意：给定有序的c数组 c[i]代表第i篇论文的引用次数，据此计算h指数。学者的h指数：至少有h篇论文引用次数为h及以上
思路：二分。范围[0,n]（注意是闭区间）
*/
class Solution {
public:
    int hIndex(vector<int>& c) {
        int l=0,r=c.size(),n=r,h=0;
        while(l<=r){
            int mid=(l+r)/2;
            int id=min(n-1,n-mid);//下标注意不要越界！
            if(c[id]>=mid){
                h=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return h;
    }
};