/*
题意：选课 拓扑排序 返回合法序列
思路：同207
*/
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        vector<int> res;
        for(auto e:edges){
            g[e[1]].push_back(e[0]); // e[1]是e[0]的前置
            ++d[e[0]];
        }
        queue<int>q;
        for(int i=0;i<n;++i){
            if(!d[i]) q.push(i);
        }
        int cnt=0;
        while(q.size()){
            int t=q.front();
            ++cnt;
            res.push_back(t);
            q.pop();
            for(auto e:g[t]){
                if(--d[e]==0) q.push(e);
            }
        }
        if(cnt==n) return res;
        else return vector<int>(0);
    }   
};