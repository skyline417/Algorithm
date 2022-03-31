/*
题意：缺失的第一个正整数
思路：桶排序
    通过一个循环 不停地swap 把每个数放在对应下标的位置上
    然后从前往后遍历 如果哪个位置不是那个数 就是答案
    时间复杂度O(n) 空间O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();++i){
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                //放[1,n]   
                //nums[nums[i]-1]: i这个位置上当前的数(nums[i])应该放的位置(nums[i]-1)上的数(nums[nums[i]-1]) 如果不是nums[i]
                swap(nums[i],nums[nums[i]-1]);
                //就把nums[i]放到它该放的位置上去 
                //所以while的每次循环 都有一个数被放到正确的位置，总共最多执行n次！ 复杂度O(n)
            }
        }
        int res=n+1;
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1){
                res=i+1;
                break;
            }
        }
        return res;
    }
};