#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int x1[N],y1[N],x2[N],y2[N],sx[N],sy[N];
int main(){
	int T;
	cin>>T;
	for(int Case=1;Case<=T;++Case){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>x1[i]>>y1[i]>>x2[i+1]>>y2[i+1];
		}
		
		sort(x1+1,x1+k+1);
		sort(y1+1,y1+k+1);
		sort(x2+1,x2+k+1);
		sort(y2+1,y2+k+1);
		
		
		
		for(int i=1;i<=k;++i){
			sx1[i]=sx1[i-1]+x1[i];
			sy1[i]=sy1[i-1]+y1[i];
			sx2[i]=sx2[i-1]+x2[i];
			sy2[i]=sy2[i-1]+y2[i];
		}
		
		for(int i=1;i<=k;++i){
			sx1[]
		}
		
	}
}
