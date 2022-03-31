/*
题意：把数组排成最小的数
思路：key在cmp函数
*/
class Solution {
public:
    static bool cmp(string a, string b){ //注意要加static 类的函数 否则只是实例的函数
        return a+b<b+a;
    }
    string minNumber(vector<int>& nums) {
        vector<string>v(nums.size());
        for(int i=0;i<nums.size();++i) v[i]=to_string(nums[i]);
        sort(v.begin(),v.end(),cmp);
        string res;
        for(auto e:v) res+=e;
        return res;
    }
};