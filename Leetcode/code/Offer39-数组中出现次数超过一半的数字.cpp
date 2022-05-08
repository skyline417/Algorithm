/*
题意：求数组中出现次数超过一半的数字（一定是超过 等于一半都不行）O(1)空间
思路：方法一：捏着一个数 后面碰到相同的 cnt++ 不等的 cnt-- cnt=0的时候 换个数拿着 
    最后手里捏着的那个数 就是答案
    （因为出现次数超过一半的数 它的出现次数超过其他全部数字出现次数总和）
    方法二：第k大的数->第n/2大的数 （快速选择算法 一次快排(partition) 时间复杂度O(n)）
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=nums[0],cnt=0;
        for(auto e:nums){
            if(e==val){
                ++cnt;
            }else{
                if(cnt>0) --cnt;
                else{
                    cnt=1;
                    val=e;
                }
            }
        }
        return val;
    }
};
/*
20220501 第2次 没想起来
*/