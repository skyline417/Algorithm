/*
题意：找到每个二元组（区间）的最近的右边的二元组。
思路：先排序，在每个二元组后面放上它的index，然后二分。
*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& q) {
        int n=q.size();
        for(int i=0;i<n;++i) q[i].push_back(i);
        sort(q.begin(),q.end());
        vector<int>ans(n,-1);
        for(int i=0;i<n;++i){
            int l=0,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(q[mid][0]>=q[i][1]){
                    ans[q[i][2]]=q[mid][2];
                    r=mid-1;
                }else l=mid+1;
            }
        }
        return ans;
    }
};