/*
题意：旋转数组的最小数字
思路：如果无重复元素，可用二分，时间复杂度O(logn)（单调性：前一段都>=q[0], 后一段都<q[0]）
    本题有重复元素，需要把末尾的数删到严格小于开头的数，再二分，时间复杂度O(n)
*/
class Solution {
public:
    int minArray(vector<int>& q) {
        int l=0, r=q.size()-1;
        int ans=q[0];
        while(r>=0 && q[r]==q[l]) --r;
        while(l<=r){
            int mid = (l + r) >> 1;
            if(q[mid]>=q[0]){
                l=mid+1;
            }else{
                ans=q[mid];
                r=mid-1;
            }
        }
        return ans;
    }
};