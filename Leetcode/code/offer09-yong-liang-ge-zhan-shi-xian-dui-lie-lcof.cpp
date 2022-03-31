/*
题意：yong-liang-ge-zhan-shi-xian-dui-lie-lcof
思路：主栈s1和辅助栈s2，
    当取队首时，把主栈全倒进辅助栈，弹出辅助栈栈顶，再把辅助栈元素全倒回主栈
*/
class CQueue {
    stack<int>s1,s2;
public:
    
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty()) return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */