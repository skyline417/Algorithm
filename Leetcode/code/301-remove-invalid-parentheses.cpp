/*题解：
    剪枝：通过遍历括号序列可以确定需要删几个左括号和右括号
*/
class Solution {
public:
    set<string>ss;
    bool flag=0;
    vector<string>ans;
    int n, l=0, r=0;
    string S;
    bool check(string t){
        int tmp=0;
        for(auto e:t){
            if(e=='(') ++tmp;
            else if(e==')') --tmp;
            if(tmp<0) return 0;    
        }
        if(!tmp) return 1;
        return 0;
    }   
    void dfs(int ll, int rr, int vis[], int p){ //左右选了几个，选的情况，到第几位了 
        if(ll==l&&rr==r){
            string t="";
            for(int i=0;i<n;++i){ 
                if(!vis[i]) t+=S[i];
            }
            if(check(t)) ss.insert(t);
            return;
        }
        if(p==n) return;

        
        //每位 选或不选

        if(S[p]=='('||S[p]==')'){ //非括号必不删
            vis[p]=1;//删第p位
            dfs(ll+(S[p]=='('),rr+(S[p]==')'),vis,p+1); //布尔表达式记得加括号
        }

        vis[p]=0; //不删第p位
        dfs(ll,rr,vis,p+1);
    }
    vector<string> removeInvalidParentheses(string s){
        
        n=s.size();
        S=s;

        for(int i=0;s[i];++i){
            if(s[i]=='(') ++l;
            else if(s[i]==')'){
                if(!l) ++r; //应该删掉的右括号数
                else --l;
            }
        }

        int vis[30]={0};
        dfs(0,0,vis,0);
        
        for(auto e:ss) ans.push_back(e);
        return ans;
    }
};