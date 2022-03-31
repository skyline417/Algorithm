/*
题意：
    移除k位 使剩下的数字最小
思路：
    方法1：栈 类似316题 考虑什么时候入什么时候出
    方法2：贪心（也是类似单调栈）
*/

//1
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

//2
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(auto c:num){

            //决定 前面的位删不删（删到前一位<c为止）//类似于单调栈！
            while(k && res.size() && c<res.back()){
                --k;//每删一个 k-1
                res.pop_back();
            }

            res += c;//这一位是一定要加上的
        }

        while(k--) res.pop_back();//如果没删到k个。继续删（从后往前）

        //前导0
        k=0;
        while(k<res.size() && res[k]=='0') ++k;
        if(k==res.size()) res+='0';//全是0 删完了
        return res.substr(k);//从第k位开始 取到结尾的子串
    }
};
