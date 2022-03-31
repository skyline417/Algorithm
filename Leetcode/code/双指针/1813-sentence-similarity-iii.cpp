/*
题意：一个句子能在中间插入一段话变成另一个句子 则它俩相似 判断两个句子是否相似
思路：双指针
*/
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence2.size()>sentence1.size()) swap(sentence1,sentence2);

        stringstream s1, s2;
        s1 << sentence1;
        s2 << sentence2;

        string a[100], b[100];
        int n1=0,n2=0;
        string str;
        
        //把句子存成字符串数组
        while(s1>>str) a[n1++]=str;
        while(s2>>str) b[n2++]=str;

        int i=0,j=0;
        while(i<n2 && a[i]==b[i]) ++i; //相等 从前往后
        while(j<n2 && a[n1-j-1]==b[n2-j-1]) ++j; //相等 从后往前
        
        return i+j>=min(n1,n2); //看两个指针有没有相遇
    }
};