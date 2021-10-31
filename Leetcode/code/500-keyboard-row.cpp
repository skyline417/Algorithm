/*
题意：输出 用键盘的一行 可以输出的单词
*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string l[]={"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        set<char>s[3];
        for(int i=0;i<3;++i){
            for(int j=0;l[i][j];++j){
                s[i].insert(l[i][j]);
            }
        }
        vector<string>v;
        for(auto e:words){
            bool a[3]={0};
            for(int i=0;e[i];++i){
                for(int j=0;j<3;++j)
                    if(s[j].count(e[i])) a[j]=1;
            }
            if(a[0]+a[1]+a[2]==1) v.push_back(e);
        }
        return v;
    }
};