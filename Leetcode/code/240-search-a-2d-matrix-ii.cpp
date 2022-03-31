/*
题意：二维数组中的查找
思路：判断右上角的值和target的大小关系 可以每次排除一行一列
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return 0;
        int d=matrix.size()-1, r=matrix[0].size()-1, l=0, u=0;
        while(u<=d && l<=r){
            if(matrix[u][r] == target) return 1;
            if(matrix[u][r] < target) ++u; else --r;
        }
        return 0;
    }
};