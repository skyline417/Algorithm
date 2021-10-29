/*题解：
    循环数列，把数列乘2倍再做单调栈即可
*/
class Solution {
public:
    int tt=0;
    int stk[20005];
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size(), n2=n<<1;
        vector<int> num=nums; for(auto e:nums) num.push_back(e);
        vector<int> ans(n2);
        for(int i=n2-1;i>=0;--i){
            while(tt && stk[tt]<=num[i]) --tt;
            if(!tt) ans[i]=-1; else ans[i]=stk[tt];
            stk[++tt]=num[i];
        }
        vector<int> v(n);
        for(int i=0;i<n;++i) v[i]=ans[i];
        return v;
    }
};