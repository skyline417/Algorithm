/*给定n生成所有合法括号序列
左右括号数量分别为n，每次加括号改变前缀和，前缀和为0只能加左括号
*/
class Solution {
public:
    vector<string>ans;
    void dfs(int l,int r,string s,int cur){//
        if(l==0&&r==0){
            ans.push_back(s);
            return;
        }
        if(cur==0){
            dfs(l-1,r,s+'(',cur+1);
        }else{
            if(l) dfs(l-1,r,s+'(',cur+1);
            if(r) dfs(l,r-1,s+')',cur-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,n,"",0);
        return ans;
    }
};