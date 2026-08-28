class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = upper_bound(m[key].begin() , m[key].end() , make_pair(timestamp , string(1 , char(134))));
        if(it == m[key].begin())return "";
        it--;
        return it->second;
        
    }
};