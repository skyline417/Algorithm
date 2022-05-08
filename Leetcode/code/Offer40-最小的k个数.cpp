/*
题意：最小的k个数
思路：
    方法1：快速选择 复杂度O(n)
    方法2：使用堆或红黑树（set、multiset），
        时间复杂度O(nlogk)，
            对于n个数，每个数都要放到一个容量为k的二叉树（查找最大值，删除最大值，插入新值 的操作都是logk）（最大堆的话查找是O(1)）
            适用于海量数据（只需把k个数放入内存）
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