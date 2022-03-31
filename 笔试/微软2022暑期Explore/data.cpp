#include <bits/stdc++.h>
using namespace std;
int main() {
	int n=1, m=100;
	vector<vector<int>> board(n, vector<int>(m, 0));
    srand(time(0));
    freopen("output.txt","w",stdout);
    cout<<"[";
	for(int i=0; i<n; i++){
	    for(int j=0; j<m; j++){
            board[i][j]=rand() % 10;
            cout<<board[i][j];
            if(j!=m-1) cout<<",";
        }
        cout<<"],[";
    }
	//cout<<solution(board);
	return 0;
}