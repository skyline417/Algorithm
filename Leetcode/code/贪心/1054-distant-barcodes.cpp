/*
题意：重排一些数 使相邻的数不相等
思路：贪心 先间隔排最多的 然后间隔排第二多的...
    做法就是先求各数的频次 按频次从大到小排序 然后填数
*/

#define x first
#define y second

typedef pair<int,int> PII;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        unordered_map<int,int>cnt;
        for(auto e:barcodes) ++cnt[e];

        vector<PII>vec;
        for(auto& [k,v]: cnt) vec.push_back({v,k}); //频数-值

        sort(vec.begin(),vec.end(),greater<PII>());

        int n=barcodes.size();
        vector<int>res(n);
        int k=0;
        for(auto e:vec){
            while(e.x--){
                res[k]=e.y;
                k+=2;
                if(k>=n) k=1;
            }
        }

        return res;
    }
};