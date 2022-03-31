class MaxQueue{
    queue<int>q1;
    dequeue<int>q2;
public:
    MaxQueue(){

    }
    int max_value(){
        if(q1.empty()) return -1;
        return q2.back();
    }
    void push_back(int value){
        q1.push(value);
        if(q2.empty() || value >= q2.back()){
            q2.push(value);
        }
    }
    int pop_front(int value){
        if(!q1.empty()){
            int e=q1.front();
            if(e==q2.front()) {q2.pop_front();}
            q1.pop();
            return e;
        }else return -1;
    }
}