class Solution {
public:
    int strToInt(string str) {
        int minus = 1;
        int num=0;
        int i=0;
        while(i<str.size() && str[i]==' ') ++i; //先去掉前缀0
        //然后判断0之后下一个字符是啥：1.正负号 2.其他字符
        if(str[i]=='-' || str[i]=='+'){ 
            if(str[i]=='-') minus=-1; //若是负号 标记
            ++i;
        }else if(!isdigit(str[i])){ //若是其他字符，直接返回
            return num;
        }
        //开始 只处理数字
        while(i<str.size() && isdigit(str[i])){ //数字的处理放爆int
            //num=num*10+str[i]-'0';
            if(minus==1){
                //num*10+str[i]-'0'>INT_MAX
                if(num>(INT_MAX-str[i]+'0')/10) return INT_MAX;
                else num=num*10-'0'+str[i];//注意先-'0'
            }else{
                //num*10+str[i]-'0'>INT_MAX+1
                if(num-1>=(INT_MAX-str[i]+'0')/10) return INT_MIN;
                else num=num*10-'0'+str[i];
            }
            ++i;
        }
        return num*minus;
    }
};