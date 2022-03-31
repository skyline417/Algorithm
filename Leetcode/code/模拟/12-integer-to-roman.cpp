/*
题意：罗马数字
思路：见代码
*/
class Solution {
public:

    struct node{
        int x;
        string y;
    }mp[13]={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};

    string intToRoman(int num) {
        string ans;
        for(auto e: mp){
            while(num>= e.x){
                num-=e.x;
                ans+=e.y;
            }
        }
        return ans;
    }
};