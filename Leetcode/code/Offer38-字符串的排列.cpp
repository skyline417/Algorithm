/*
题意：字符串的排列 
      abb: aab, bab, bba
思路：固定当前位，将当前位与后面每一位交换 注意去重...
*/
class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        dfs(s,0);
        return res;
    }
    void dfs(string s, int p){
        if(p==s.size()-1){
            res.push_back(s);
        }else{
            bool st[26]={0};//为什么这个去重要放这而不是全局变量呢：每种字符只在此位固定一次 所以去重数组应该是放在这一层的
            for(int i=p;i<s.size();++i){
                if(st[s[i]-'a']) continue;
                st[s[i]-'a']=1;
                swap(s[i],s[p]);
                dfs(s,p+1);
                swap(s[i],s[p]);
            }
        }
    }
};