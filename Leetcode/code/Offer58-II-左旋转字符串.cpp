/*
题意：左旋转字符串，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
思路：调用3次reverse：先把前面的部分reverse，再把后面的部分reverse，最后全部reverse
*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};