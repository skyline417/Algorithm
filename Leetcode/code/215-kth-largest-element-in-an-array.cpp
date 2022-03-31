/*
题意：第k大数
思路：
    方法1：C++ nth_element使用
    方法2：基于快排的快速选择算法 O(n)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};

class Solution {
public:
    int quick_sort(vector<int>& nums, int l, int r, int k){
        if(l>=r) return nums[l];
        int i=l-1, j=r+1, p=nums[(l + r) >> 1];
        while(i<j){
            do i++; while(nums[i]>p);
            do j--; while(nums[j]<p);
            if(i<j) swap(nums[i],nums[j]); //记得最后一步是swap!
        }
        if(k<=j) return quick_sort(nums,l,j,k);//这必须是j 不能是i 否则会超时
        else return quick_sort(nums,j+1,r,k);//这里也是k哦
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums,0,nums.size()-1,k-1);
    }
};