#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("mine.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
    	
		int a,b;
    	scanf("%d%d",&a,&b);
    	int n=a+b;
		cout<<"input: "<<a<<" "<<b<<endl;
    	set<int>ss;
	/* 
		�÷�break�� 
				�����Ǹ÷�Ӯ��-�÷��������ڸ÷����ִ�Ӯ���� 
				�������÷�Ӯ��
				�������Է�Ӯ��
	 	��break��
		 		=�÷�break+�Է�break
		���÷�breakΪi�����ʱ�Է�breakΪ
	
		�Է��ڸ÷����ִε�Ӯ��
		=�Է���Ӯ��-�Է��ڶԷ��ִε�Ӯ��
		=�Է���Ӯ��-(�Է��ִ�-�÷�break) 
	*/
		if(n&1){
			//a:n/2 b:n/2+1 
			for(int i=max(a-n/2,0);i<=min(a,b);++i){
				ss.insert(i+b-(n/2+1-i));
			}
			
			for(int i=max(b-(n/2-1),0);i<=min(a,b);++i){
				ss.insert(i+a-(n/2-i));
			}
				 
		}else{
			//a:n/2 b:n/2
			for(int i=max(a-n/2,0);i<=min(a,b);++i){
				ss.insert(i+b-(n/2-i));
			}
			
			for(int i=max(b-n/2,0);i<=min(a,b);++i){
				ss.insert(i+a-(n/2-i));
			}
		}
		for(auto e:ss){
			ss.insert(n-e);
		}
		cout<<ss.size()<<endl;
		for(auto e:ss){
			cout<<e<<" ";
		}
		puts("");
        
    }
    return 0;
}
