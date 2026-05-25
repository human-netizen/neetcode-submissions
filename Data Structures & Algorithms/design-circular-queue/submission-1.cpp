class MyCircularQueue {
public:
    int capacity;
    std::vector<int> data;
    int front;
    int rear;
    int count;
    MyCircularQueue(int k) : capacity(k), front(0), rear(-1), count(k){
        
    }
    
    bool enQueue(int value) {
        if(data.size() == count){
            return 0;
        }
      data.push_back(value);
      return 1;  
    }
    
    bool deQueue() {
        if(!data.empty()){
            data.pop_back();
            return 1;
        }
        return 0;
    }
    
    int Front() {
        if(!data.empty())return data.front();
        return -1;
    }
    
    int Rear() {
        if(!data.empty())return data.back();
        return -1;
    }
    
    bool isEmpty() {
        return data.empty();
    }
    
    bool isFull() {
        return (data.size() == count)  ;
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