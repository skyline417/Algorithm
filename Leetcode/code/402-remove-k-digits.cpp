/*
题意：
    移除k位 使剩下的数字最小
思路：
    栈 类似316题 考虑什么时候入什么时候出
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>stk;
        int in=0, n=num.size(); k=n-k;//留k个

        for(int i=0;num[i];++i){
            while(!stk.empty()&&num[i]<stk.top()){
                if(in+n-i>k){ //key
                    stk.pop();
                    --in;
                }else break; //key
            }
            if(in<k){ //key
                stk.push(num[i]);
                ++in;
            }
        }
        string s,ans;
        bool flag=1;
        
        while(!stk.empty()){
            s+=stk.top();
            stk.pop();
        }

        reverse(s.begin(),s.end());
        for(int i=0;s[i];++i){
            if(flag&&s[i]=='0') continue;
            flag=0;
            ans+=s[i];
        }
        if(ans.size()==0) ans+="0";
        return ans;
    }
};