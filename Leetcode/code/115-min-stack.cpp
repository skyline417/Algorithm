/*
题意：实现一个最小栈
思路：
    方法1：两个栈 一个正常存储 一个保存最小值 和正常栈同步弹入弹出（保存最小值 所以是递减的）
    方法2：val-min 占内存差值 （但是会溢出 该方法没实现）
*/
class MinStack {
    stack<int>s, mins;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(mins.empty() || val<=mins.top()) mins.push(val); //别忘判断空呀
        s.push(val);
    }
    
    void pop() {
        if(mins.top()==s.top()) mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */