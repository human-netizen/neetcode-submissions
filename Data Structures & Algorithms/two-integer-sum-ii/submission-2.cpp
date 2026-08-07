class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0 , index2 = numbers.size() - 1;
        while(index1 < index2){
            int sum = numbers[index1] + numbers[index2];
            if(sum == target)return vector<int>{index1 + 1 , index2 + 1};
            if(sum > target)index2--;
            else index1++;
        }     
    }
};
