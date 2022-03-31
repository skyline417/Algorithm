/*
题意：二进制手表
思路：10个灯 点亮turnedOn个 问一共有多少种不同组合 DFS
*/
class Solution {
public:
    int a[10];
    vector<string> res;
    vector<string> readBinaryWatch(int turnedOn) {
        dfs(0, turnedOn);
        return res;
    }
    void dfs(int id, int turnedOn){
        if(!turnedOn){
            int h=0, m=0;
            int t=1;
            for(int i=0;i<4;++i){
                if(a[i]){
                    h+=t;
                }
                t<<=1;
            }
            t=1;
            for(int i=4;i<10;++i){
                if(a[i]){
                    m+=t;
                }
                t<<=1;
            }
            if(h<12 && m<60) res.push_back( to_string(h) +":"+ (m<10?"0":"") + to_string(m) );
            return;
        }
        
        if(id==10) return;

        //一共10个位置，每一个位置，选或不选
        dfs(id+1,turnedOn);
        
        a[id]=1;
        dfs(id+1,turnedOn-1);
        a[id]=0;

    }
};