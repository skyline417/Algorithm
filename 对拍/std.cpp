#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("std.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<"input: "<<a<<" "<<b<<endl;
        vector<int> ans;
 
        int mid=(a+b)/2;
        if((a+b)&1)
            for(int i=mid-min(a,b);i<=mid;i++)
            {
                ans.push_back(i);
                ans.push_back(a+b-i);
            }
        else
            for(int i=mid-min(a,b);i<=mid;i+=2)
            {
                ans.push_back(i);
                if(i!=a+b-i)
                    ans.push_back(a+b-i);
            }
 
        cout<<ans.size()<<endl;
        sort(ans.begin(),ans.end());
        for(auto u:ans)
        {
            printf("%d ",u);
        }
        cout<<endl;
    }
    return 0;
}
