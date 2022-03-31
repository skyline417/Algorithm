/*
题意：翻转单词顺序
思路：
*/
class Solution {
public:
    string reverseWords(string s) {
        string res;
        for(int i=0;i<s.size();++i){ //注意终止条件不能写s[i]
            if(s[i]==' ') continue;
            string str;
            int j=i;
            while(j<s.size() && s[j]!=' '){
                str+=s[j];
                ++j;
            }
            reverse(str.begin(), str.end());
            res+=str;
            res+=" ";
            i=j;
        }
        if(res.back()==' ') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};