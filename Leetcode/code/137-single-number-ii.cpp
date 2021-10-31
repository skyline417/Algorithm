/*
题意：
    给你一个整数数组 nums ，除某个元素仅出现1次外，其余每个元素都恰出现3次。请你找出并返回那个只出现了一次的元素。
思路：   
    状态机+真值表
    随缘过题~
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0;
        for(auto e:nums){
            one = one ^ e & ~two;
            two = two ^ e & ~one;
        }
        return one;
    }
};