/*
题意：选课 拓扑排序
思路：拓扑排序：
        整理出所有边：前置->后，后，后，后， 同时统计每个课的前置数d
        将前置数为0的加入队列q
        q不为0则出队
            它连的所有结点（它的后继）的前置数-1 然后将前置数减到0的加入队列
*/
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n); //g[i][j] i是j的前置条件
        vector<int> d(n);
        for(auto& e:edges){
            int b=e[0], a=e[1];
            g[a].push_back(b);//a是b的前置
            ++d[b];//b的前置数+1
        }
        queue<int>q;
        for(int i=0;i<n;++i){ //将前置数为0的加入队列
            if(!d[i]) q.push(i);
        }
        int cnt=0;
        while(q.size()){
            int t=q.front();
            q.pop();
            ++cnt;//该课可以完成（没有前置）
            for(auto i:g[t]){ //t作为前置的课程i，i的前置全部-1，然后看哪个i前置数为0了，加到队列里
                if(--d[i]==0) q.push(i);
            }
        }
        return cnt==n;
    }
};