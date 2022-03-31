/*
题意：找到离x最近的k个元素
思路：
    1) 堆 维护k小值 时间复杂度 nlogn
    2) 但是还有二分 logn复杂度的做法
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>heap;//默认大顶堆，把大的弹出去，剩下k个小的
        for(auto e:arr){ //k个最小的 在堆里
            heap.push({abs(e-x),e});
            if(heap.size()>k) heap.pop();
        } 
        vector<int>res;
        while(heap.size()) res.push_back(heap.top().second),heap.pop();
        sort(res.begin(),res.end());
        return res;
    }
};