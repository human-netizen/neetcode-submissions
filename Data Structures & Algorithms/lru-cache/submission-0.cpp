class LRUCache {
public:
    unordered_map<int,int> cnt , mp;
    queue<int>q;
    int capacity;
    int curSize;
    LRUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end() && cnt[key] != 0)return mp[key];
        return -1;
    }
    
    void put(int key, int value) {
        mp[key] = value;
        cnt[key]++;
        q.push(key);
        if(cnt[key] == 1){
            curSize++;
        }
        while(curSize > capacity && !q.empty()){
            int top = q.front();
            q.pop();
            cnt[top]--;
            if(cnt[top] == 0){
                curSize--;
                mp.erase(top);
            }
        }
    }
};
