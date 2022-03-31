/*
题意：螺旋矩阵
思路：
*/

//我自己一开始写的 需要标记
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(!matrix.size()) return res;
        int h=matrix.size(), w=matrix[0].size();
        int x=0, y=0, d=0;
        int f=101;
        while(res.size()<w*h){
            if(d==0){
                while(y<w&&matrix[x][y]!=f){
                    res.push_back(matrix[x][y]);
                    matrix[x][y]=f;
                    ++y;
                }
                --y; ++x;
                d=1;
            }else if(d==1){
                while(x<h&&matrix[x][y]!=f){
                    
                    res.push_back(matrix[x][y]);
                    matrix[x][y]=f;
                    ++x;
                }
                --x, --y;
                d=2;
            }else if(d==2){
                while(y>=0&&matrix[x][y]!=f){
                    res.push_back(matrix[x][y]);
                    matrix[x][y]=f;
                    --y;
                }
                ++y, --x;
                d=3;
            }else{//d=4
                while(x>=0 && matrix[x][y]!=f){
                    res.push_back(matrix[x][y]);
                    matrix[x][y]=f;
                    --x;
                }
                ++x, ++y;
                d=0;
            }
        }
        return res;
    }
};
//y总的简洁写法
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if (!n) return res;
        int m = matrix[0].size();

        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        vector<vector<bool>> st(n, vector<bool>(m));

        for (int i = 0, x = 0, y = 0, d = 0; i < n * m; i ++ ) {
            res.push_back(matrix[x][y]);
            st[x][y] = true;

            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }

            x = a, y = b;
        }

        return res;
    }
};

//看到的比较好的解法 不标记 而且短
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> res;
        if(matrix.empty()) return res;
        int rl = 0, rh = matrix.size()-1; //记录待打印的矩阵上下边缘
        int cl = 0, ch = matrix[0].size()-1; //记录待打印的矩阵左右边缘
        while(1){
            for(int i=cl; i<=ch; i++) res.push_back(matrix[rl][i]);//从左往右
            if(++rl > rh) break; //若超出边界，退出
            for(int i=rl; i<=rh; i++) res.push_back(matrix[i][ch]);//从上往下
            if(--ch < cl) break;
            for(int i=ch; i>=cl; i--) res.push_back(matrix[rh][i]);//从右往左
            if(--rh < rl) break;
            for(int i=rh; i>=rl; i--) res.push_back(matrix[i][cl]);//从下往上
            if(++cl > ch) break;
        }
        return res;
    }
};