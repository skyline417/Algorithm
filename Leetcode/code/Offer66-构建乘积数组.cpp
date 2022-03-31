/*
题意：给定a数组 求b数组 b[i]=a[0]*a[1]*...*a[i-1]*a[i+1]*...a[n-1] n<=1e5 不许用除法
思路：构造前缀积和后缀积
*/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        vector<int>left(n), right(n), b(n); //left前缀积 right后缀积
        if(!n) return b;
        left[0]=a[0], right[n-1]=a[n-1];
        for(int i=1;i<a.size();++i){//求前缀积和后缀积
            left[i]=left[i-1]*a[i];
            right[n-i-1]=right[n-i]*a[n-i-1];
        }
        b[0]=right[1], b[n-1]=left[n-2];//特殊的两个b
        for(int i=1;i<a.size()-1;++i){
            b[i]=left[i-1]*right[i+1];
        }
        return b;
    }
};