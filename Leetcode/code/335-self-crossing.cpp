/*
题意：
    无限的序列，每四个数代表向上下左右四个方向走的长度，判断路径是否会交叉。
思路：
    分类讨论，一共三种情况。
*/

class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        int n=d.size();
        for(int i=3;i<n;++i){
            if(d[i]>=d[i-2]&&d[i-1]<=d[i-3]) return 1;
            if(i>=4 && ((d[i-1]<d[i-3]&&d[i]>=d[i-2]) || (d[i-1]==d[i-3]&&d[i]+d[i-4]>=d[i-2]))) return 1;
            if(i>=5 && d[i-1]<=d[i-3] && (d[i]>=d[i-2] || (d[i-1]>=d[i-3]-d[i-5]&&d[i]>=d[i-2]-d[i-4]) || (d[i-1]==d[i-3]&&d[i]==d[i-2]-d[i-4]) )) return 1;
        }
        return 0;
    }
};