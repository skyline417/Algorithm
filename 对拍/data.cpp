#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","w",stdout);
	srand((int)time(0));
	int t=1000+rand()%1000;
	
	printf("%d\n",t);
	while(t--){
		int a=rand()%10;
		int b=rand()%10;
		printf("%d %d\n",a,b);
	}
	
//	while(t--){
//		int n=1+rand()%20;
//		for(int i=0;i<n;++i){
//			int s=1+rand()%1000;
//			printf("%d",s&1);
//		}
//		printf("\n");
//	}



// 	int n,m,p,i,l,b,a,x,y;
//	char ab[27]="abcdefghijklmnopqrstuvwxyz";
// 	//char a[4]="xiu";
// 	srand((int)time(0));  //调用srand()函数，以系统时间为随机种子
//
//	 //n = 1+rand()%1000;  //随机生成一个[1,1000]的自然数
// 	n=1+rand()%50000;
//	printf("%d\n",n);
////	int k=1+rand()%50000;
////	printf("%d\n",k);
// 	while(n--){
//
//
//		//if(rand()%2) flag=1; else flag=-1;
//		//m=rand()%8*flag;
//		printf("40320\n");
//		int a[8];
//		for(int i=0;i<8;++i){
//			a[i]=i+1;
//			printf("%d ",a[i]);
//		}
//		puts("");
//		while(next_permutation(a,a+8)){
//			for(auto e:a) printf("%d ",e);
//			puts("");
//		}
////		for(i=0;i<m;i++){
////
////				int j=1+rand()%20;
////				printf("%d ",j);
////		}
////		printf("\n");
//	}
//
// 	/*for(i=0;i<n;i++){
//        x = rand()%3;
//        printf("%d",x);
//        //y = rand()%1000;
//        //printf("%d\n",y);
//
// 	}
//
//
// 	/*printf("%d\n",n); // 输出随机生成的自然数
// 	for(int i=0;i<n;i++){
// 		l=1+rand()%5000;
// 		for(int j=0;j<l;j++){
// 			b=rand()%3;//[0,2]
// 			printf("%c",a[b]);
//		}
//		printf("\n");
//	}*/
 	return 0;
}

