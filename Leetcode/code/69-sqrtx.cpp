/*
题意：二分找平方根
*/
class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if((long long)mid*mid<=x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};