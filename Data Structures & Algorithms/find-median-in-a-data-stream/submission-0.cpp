class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(smallHeap.size() - 1 > largeHeap.size()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(!largeHeap.empty()){
            if(smallHeap.top() > largeHeap.top()){
                int one = largeHeap.top();
                int two = smallHeap.top();
                smallHeap.pop();
                largeHeap.pop();
                smallHeap.push(one);
                largeHeap.push(two);
            }
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size())return (smallHeap.top() + largeHeap.top()) / 2.00;
        return smallHeap.top();
    }
};
