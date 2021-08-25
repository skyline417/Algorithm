#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
    int x,y,id;
    bool operator < (const node& t) const {
        return x<t.x;
    }
}c[N];
bool cmp1(node& a, node& b){
    return a.id<b.id;
}
int a[N],S[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        int flag=0;
        int f=1;
        while(flag==0){
        	bool is=0;
        	if(f&1){
        		for(int i=1;i<=n-2;i+=2){
        			if(a[i]>a[i+1]){
        				//cout<<a[i]<<" "<<a[i+1]<<endl;
        				swap(a[i],a[i+1]);
        				is=1;
					}
				}
				//for(int i=1;i<=n;i++) cout<<a[i]<<" "; puts("");
			}else{
				for(int i=2;i<=n-1;i+=2){
        			if(a[i]>a[i+1]){
        				swap(a[i],a[i+1]);
        				is=1;
					}
				}
				//for(int i=1;i<=n;i++) cout<<a[i]<<" "; puts("");
			}
			++f;
			++ans;
			
			if(is){
				flag=0;
			}else{
				--flag;
			}
			if(flag==-2){
				break;
			}
			
		}
		//cout<<"ans: ";
        printf("%d\n",ans-1);
    }
    return 0;
}
