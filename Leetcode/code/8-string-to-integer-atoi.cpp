/*
题意：atoi
思路：考虑各种情况 比较繁
*/
class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        bool st=0;
        int flag=1;
        for(int i=0;s[i];++i){
            if(!st && s[i]==' ') continue; //如果还没碰到数且是空格
            if(isdigit(s[i])){ //如果是数 
                st=1; //数字开始了
                
                if(ans <= (INT_MAX - (s[i]-'0')) / 10 ) { //防溢出
                    ans=ans*10+(s[i]-'0'); //转换成int
                }else {
                    if(flag==1) return INT_MAX;else return INT_MIN; //溢出 
                }

            }else{ //不是数字和前导空格的其他字符（其他字符和数后面的空格）
                if( !st && (s[i]=='-'||s[i]=='+')  ){ //如果是前导符号
                    st=1;// 数开始了
                    if(s[i]=='-') flag=-1; //符号记录一下
                }else break; //否则结束
            }
        }

        ans*=flag;

        return ans;
    }
};