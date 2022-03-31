/*
题意：判断矩阵中是否存在单词
思路：dfs
*/
class Solution {
public:
    int dir[4][2]={
        -1,0,
        1,0,
        0,-1,
        0,1
    };
    bool st[205][205];
    bool flag=0;
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]==word[0]){
                    st[i][j]=1;
                    dfs(board, word, 1, i, j);
                    if(flag) return 1;
                    st[i][j]=0;
                }
            }
        }
        return 0;
    }

    
    void dfs(vector<vector<char>>& board, string word, int u, int x, int y){
        if(flag) return;
        if(u==word.size()){ //注意 这里直接返回1是不可以的 只会返回到上一层 而你上一层又没接受这个值...
            flag=1;
            return;
        }

        for(int i=0;i<4;++i){
            int nx=x+dir[i][0], ny=y+dir[i][1];
            if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size() && !st[nx][ny] && board[nx][ny]==word[u]){
                st[nx][ny]=1;
                dfs(board,word,u+1,nx,ny);
                st[nx][ny]=0;     
            }
        }
    }

};