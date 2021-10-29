#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={5,6,3,2,1};
    int n=5;
    do{
        for(int i=0;i<n;++i) printf("%d ",a[i]);
        puts("");
    }while(next_permutation(a,a+n));
}
/*
结论：next_permutation是对数组中 元素的值（不是数组的下标） 进行全排列 顺序是从小到大 
如果已经是最大的排列 比如 654321 就不会再有
*/