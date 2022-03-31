/*
题意：二维有序矩阵 找目标值
思路：把矩阵拉成一维数组 二分
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h=matrix.size(), w=matrix[0].size();
        if(!h || !w) return 0;
        int l=0, r=w*h-1, ans=0;
        while(l<=r){
            int m=(l+r)/2;
            if(matrix[m/w][m%w]==target){
                return 1;
            }else if(matrix[m/w][m%w]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return 0;
    }
};