#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=60;
string s[N+5];//2^0 ~ 2^N 字符串 
int main(){
	for(int i=0;i<=N;++i){
		ll val=1ll<<i; //2^i
		while(val){
			s[i]+=val%10+'0';
			val/=10;
		}
		reverse(s[i].begin(),s[i].end());
	}
	
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int val=n;
        string str;
        while(val){
        	str+=val%10+'0';
        	val/=10;
		}
		reverse(str.begin(),str.end());
		
		int ans=100;
        for(int i=0;i<=N;++i){
        	int len=0; //按顺序 匹配上的公共字符的长度 
        	for(char e:str){
        		if(s[i][len]==e){
        			++len;
				}
				int tmp=(str.size() - len) + (s[i].size() - len);
				ans=min(ans, tmp); //操作数=需要erase的+需要add的 
			}
        }
        printf("%d\n",ans);
    }
    return 0;
}
