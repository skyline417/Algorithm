class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int a[10],m=0;
        while(n){
            a[m++]=n%10;
            n/=10;
        }
        sort(a,a+m);
        do{
            if(a[0]==0) continue;
            int t=0;
            for(int i=0;i<m;++i) t=t*10+a[i];
            while(!(t&1)) t>>=1;
            if(t==1) return 1;
        }while(next_permutation(a,a+m));
        return 0;
    }
};
/*
题意：判断n包含的数字重排是否能组成2的幂
思路：数字全排列，然后判断它是不是2的幂
*/