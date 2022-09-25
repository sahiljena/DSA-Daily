class MyCircularQueue {
public:
    
    int size=0;
    int currSize=0;
    deque<int> ds;
    
    MyCircularQueue(int k) {
        size=k;
    }
    
    void showdq(deque<int> g)
    {
        deque<int>::iterator it;
        for (it = g.begin(); it != g.end(); ++it)
            cout <<' '<< *it;
        cout << '\n';
    }
    
    bool enQueue(int value) {
        if(currSize>=size) return false;
        
        ds.push_back(value);
        // showdq(ds);
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(currSize==0) return false;
        ds.pop_front();
        // showdq(ds);
        currSize--;
        return true;
    }
    
    int Front() {
        // showdq(ds);
        if(currSize==0) return -1;
        return ds.front();
    }
    
    int Rear() {
        // showdq(ds);
        if(currSize==0) return -1;
        return ds.back();
    }
    
    bool isEmpty() {
        // showdq(ds);
        return currSize==0;
    }
    
    bool isFull() {
        // showdq(ds);
        return currSize==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */