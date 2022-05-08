/*
题意：求1+2+...+n 不能用乘除法 if...else, for, switch...case 等关键字
思路：方法一：短路运算
*/

//方法一
class Solution {
public:
    int sumNums(int n) {
        int res = n;
        n > 0 && (res += sumNums(n - 1)); //短路
        return res;
    }
};