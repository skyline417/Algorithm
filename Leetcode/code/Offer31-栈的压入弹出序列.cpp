/*
题意：栈的压入弹出序列
思路：模拟(要写得简洁还是不容易的)
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size()) return false;
        stack<int>s;
        int j=0;
        for(int i=0;i<pushed.size();++i){
            s.push(pushed[i]);
            while(!s.empty() && popped[j]==s.top()){
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};