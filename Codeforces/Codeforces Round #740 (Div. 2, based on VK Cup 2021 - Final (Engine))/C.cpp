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
int a[N],S[N],d[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&k[i]);
            for(int j=0;j<k[i];++j){
            	scanf("%d",&a[i][j]);
			}
			sort(a[i],a[i]+k[i]);
			a[k[i]]=a[k[i]-1];
			int t=0;
			for(int j=0;j<k[i];++j){
				d[i]=max(d[i],(a[i][j]-a[i][j+1]))
				if(t+j<a[i][j]){
					t=a[i][j];
				}
			}
			ans=max(ans,)
        }
        printf("%d\n",ans);
    }
    return 0;
}
