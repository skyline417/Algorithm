/*
题意：翻转单词 "I am a student. " -> "student. a am I"
思路：翻转两次：先对每个单词翻转，再将整个句子翻转
*/
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i ++ ){
            int j = i;
            while (j < s.size() && s[j] != ' ') j ++ ;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};