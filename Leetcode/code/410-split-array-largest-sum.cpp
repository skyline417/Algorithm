/*
题意：
    将长为n的数组划分成m组，使各组和的最大值最小，输出这个值；
思路：
    二分答案。若mid满足答案条件（分成m组，每组和<=mid），则继续找mid左边（使答案最小）
*/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=1e9,ans=0;
        while(l<=r){
            int mid=l+r>>1;
            //check

            bool flag=1;
            int cur=0,cnt=1;//cnt是组数，cur是当前组的和
            for(int i=0;i<nums.size();++i){
                if(nums[i]>mid){flag=0;break;}
                if(cur+nums[i]>mid){
                    cur=nums[i];
                    ++cnt;
                }else{
                    cur+=nums[i];
                }
                if(cnt>m) break;
            }
            if(cnt>m&&flag) flag=0;

            if(flag){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};