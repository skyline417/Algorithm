#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int A[N + 5], len;
void out(){
    for(int i=1;i<=len;++i) cout<<A[i]<<" ";
    puts("");
}
void heapPermute(int n)
{
    if (n == 1)
    {
        cout<<"n=1: ";
        out();
    } else {
        for (int i = 1; i <= n; i++)
        {
            heapPermute(n - 1);
            if (n & 1){
                swap(A[1], A[n]);
                cout<<"odd: "<<"swap(A[1]="<<A[1]<<", A["<<n<<"]="<<A[n]<<"): ";
                out();
            }else{
                swap(A[i], A[n]);
                cout<<"even: "<<"swap(A["<<i<<"]="<<A[i]<<", A["<<n<<"]="<<A[n]<<"): ";
                out();
            }
        }
    }
    
}
int main()
{
    while (cin >> len)
    {
        for (int i = 1; i <= len; i++)
            A[i] = i;
        heapPermute(len);
    }
    return 0;
}
