/*
题意：最小的k个数
思路：
    方法1：我用快速选择做的 我以为复杂度是O(n) 怎么不是吗
    方法2：堆 还没学习
*/

class Solution {
public:
    int quick_sort(vector<int>& arr, int l, int r, int k){
        if(l>=r) return arr[l];
        int i=l-1, j=r+1, x=arr[l+r>>1];
        while(i<j){
            do i++; while(arr[i] < x);
            do j--; while(arr[j] > x);
            if(i<j) swap(arr[i],arr[j]);
        }
        if(k<=j) return quick_sort(arr, l, j,k); //这必须是j 不能是i
        else return quick_sort(arr,j+1, r, k);
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>res(k);
        if(!k) return res;
        quick_sort(arr, 0, arr.size()-1, k-1);
        
        for(int i=0;i<k;++i){
            res[i]=arr[i];
        }
        return res;
    }   
};