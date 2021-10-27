//题解：对nums2从右到左做单调栈，线性做nums2数值对index的映射，输出单调栈结果（由nums1数值索引）
class Solution {
public:
    map<int,int>p;
    int ans[10005];
    int tt=0;
    int stk[10005];
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size(), m=nums2.size();
        vector<int> v(n);

        for(int i=m-1;i>=0;--i){
            p[nums2[i]]=i;
            while(tt && stk[tt]<nums2[i]) --tt;
            if(!tt) ans[i]=-1;
            else ans[i]=stk[tt];
            stk[++tt]=nums2[i];
        }

        for(int i=0;i<n;++i) v[i]=ans[p[nums1[i]]];
        
        return v;
       
    }
};