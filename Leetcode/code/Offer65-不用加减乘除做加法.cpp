/*
题意：不用加减乘除做加法
思路：看成两个二进制数，
    当前位 0+0=0, 0+1=1, 1+1=0（进位1） 当前位可以用异或操作
    进位 只有1+1需要进位 可以用与操作 并且把当前位左移 供下一位加上这个进位
*/
class Solution {
public:
    int add(int a, int b) {
        int sum, carry;
        while(b){
            sum = a ^ b;
            carry = (unsigned int) (a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};