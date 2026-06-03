class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        auto IdxFinder = [&](this auto self , int lo , int hi)-> int{
            if(lo == hi)return lo;
            int mid = (lo + hi) / 2;
            if(nums[mid] < nums[0])return self(lo , mid);
            return self(mid + 1 , hi);
        };
        int idx;
        if(nums[0] < nums.back())idx = 0;
        else idx = IdxFinder(1 , nums.size());
        int n = nums.size();
        cout << idx << endl;
        auto ansFinder = [&](this auto self , int lo , int hi) -> int{
            if(lo == hi){
                if(nums[(lo + idx) % n] == target)return lo;
                return -1;
            }
            int mid = (lo + hi) / 2;
            cout << nums[(mid + idx) % n] << " " ;
            if(nums[(mid + idx)%n] >= target)return self(lo , mid);
            return self(mid + 1 , hi);
        };
        int ans =  ansFinder(0 , n - 1);
        if(ans != -1){
            ans += idx;
            ans %= n;
        }
        return ans;
    }
};
