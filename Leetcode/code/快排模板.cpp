#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector<int>&a, int l, int r){
    if(l==r) return;
    int x=a[l+r>>1],i=l-1, j=r+1;
    while(i<j){
        do ++i; while(a[i]<x); //原本写的<= >=
        do --j; while(a[j]>x);
        if(i<j) swap(a[i],a[j]);//原本写的！=
    }
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
    return;
}

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    quick_sort(a, 0, n-1);
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    return 0;
}