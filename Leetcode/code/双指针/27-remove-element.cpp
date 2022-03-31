/*
题意：原地移除值特定值的元素
思路：和26题一模一样
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};