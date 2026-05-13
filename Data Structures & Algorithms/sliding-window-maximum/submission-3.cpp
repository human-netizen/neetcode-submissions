class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        vector<int>res;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < k - 1 ; i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
        }
        for(int i = k - 1 ; i < n ; i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
            cout << pq.top() << " ";
            res.push_back(pq.top());
            mp[nums[i - k + 1]]--;
            while(!pq.empty() && mp[pq.top()] == 0)pq.pop();
        }
        cout << endl;
        return res;
    }
};
