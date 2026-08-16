class Solution {
public:
    int bin(int lo , int hi , vector<int>&nums){
        int len = nums.size();
        if(lo == hi)return nums[lo];
        int mid = (lo + hi) / 2;
        if(nums[mid] < nums[0])return bin(lo , mid , nums);
        return bin(mid + 1 , hi , nums);

    }
    int findMin(vector<int> &nums) {
        if(nums.size() == 1 || nums[0] < nums.back())return nums[0];
        return bin(1 , nums.size() - 1 , nums);
    }
};
