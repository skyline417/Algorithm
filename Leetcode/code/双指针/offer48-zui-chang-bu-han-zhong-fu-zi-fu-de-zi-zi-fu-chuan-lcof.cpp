/*
题意：最长不含重复字符的子字符串
思路：hash表存每个字母的数量 双指针 和第3题一样
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int k=0, maxn=0;
        unordered_map<int,int>st; //key直接是字母的char值了
        for(int i=0; s[i]; ++i){
            ++st[ s[i] ];
            while(st[ s[i] ]>1){
                --st[s[k++] ]; //k指针右移的时候 它经过的字母的计数器都要--
            }
            maxn=max(maxn,i-k+1);
        }
        return maxn;
    }
};