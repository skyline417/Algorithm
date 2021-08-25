#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
int b[2],a[10];


int dfs(int id, int ){
	for(int i=a[id];i<10;++i){
		
	}
}

int main(){
	set<int>s1;
	//for(int i=0;i<10;++i) s1.insert(i);
	s1.insert(1);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(6);
	//auto pos=s1.find(11);
	//cout<<*pos<<endl;
	//for(auto it=s1.begin();it!=s1.end();++it) cout<<(*it)<<endl;
	auto p = s1.lower_bound(3);
	cout<< *p <<endl;
					
}
