class LRUCache {
public:
    unordered_map<int,int> cnt , mp;
    stack<int>q;
    int capacity;
    int curSize;
    LRUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
    }
    
    int get(int key) {
       
        if(cnt[key] != 0)return mp[key];
        return -1;
    }
    
    void put(int key, int value) {
        mp[key] = value;
        cnt[key]++;
        q.push(key);
        if(cnt[key] == 1){
            curSize++;
        }
        cout << "updating " << key << " " << curSize << " " << cnt[key] << endl;
        while(curSize > capacity){
            int top = q.top();
            q.pop();
            //cout << top << " " << curSize << " " << capacity << endl;
            cnt[top]--;
            cout <<"removeing " << top << " " << cnt[top] << endl;
            if(cnt[top] == 0){
                curSize--;
                mp.erase(top);
            }
        }
    }
};
