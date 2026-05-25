class MyCircularQueue {
public:
    int capacity;
    std::vector<int> data;
    int front;
    int rear;
    int count;
    MyCircularQueue(int k) : capacity(k), front(0), rear(-1), count(0){
        
    }
    
    bool enQueue(int value) {
        if(count == capacity){
            return 0;
        }
      data.push_back(value);
      front++;
      count++;
      return 1;  
    }
    
    bool deQueue() {
        if(count){
            rear++;
            count--;
            return 1;
        }
        return 0;
    }
    
    int Rear() {
        if(count)return data[front - 1];
        return -1;
    }
    
    int Front() {
        if(count)return data[rear];
        return -1;
    }
    
    bool isEmpty() {
        return !count;
    }
    
    bool isFull() {
        return (count == capacity)  ;
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