/*
题意：去掉重复字母，输出字典序最小的答案
思路：
    用一个栈处理答案
*/
class Solution {
public:
    int tt=0, stk[10005],cnt[10005],c[10005];
    string removeDuplicateLetters(string s) {

        for(int i=0;s[i];++i) ++cnt[s[i]-'a'];

        for(int i=0;s[i];++i){
            while(tt&&stk[tt]>=s[i]-'a'&&!c[s[i]-'a']){ //栈不为空&&栈顶>=当前&&栈里没有当前值
                if(cnt[stk[tt]]>=1){ //栈顶值后面还有 则可以弹出
                    --c[stk[tt]];//该元素在栈内有几个
                    --tt;
                }else break;
            }
            if(!c[s[i]-'a']) { //如果栈里没有则入栈
                stk[++tt]=s[i]-'a';
                ++c[s[i]-'a'];
            }
            --cnt[s[i]-'a'];//该元素在串中还剩下几个
        }

        string str="";
        while(tt) str+=stk[tt--]+'a';
        reverse(str.begin(),str.end());
        return str;
    }
};