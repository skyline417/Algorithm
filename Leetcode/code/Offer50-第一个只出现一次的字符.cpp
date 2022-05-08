/*
题意：第一个只出现一次的字符
思路：哈希表 存 每个字符出现的次数
*/
class Solution {
public:
    char firstUniqChar(string s) {
        int mp[26]={0};
        for(int i=0; i<s.size(); ++i) ++mp[s[i]-'a'];
        char ans=' ';
        for(auto e:s)
            if(mp[e-'a']==1) {
                ans=e;
                break;
            }
        return ans;
    }
};