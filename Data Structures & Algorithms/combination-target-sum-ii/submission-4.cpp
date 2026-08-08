class Solution {
public:
    vector<int> candidates;
    vector<vector<int> > sols;
    void backtrack(vector<int>&cur , int i , int target){
        if(target == 0){
            sols.push_back(cur);            
            return;
        }
        if(i == candidates.size())return;
        if(target < 0)return;
        cur.push_back(candidates[i]);
        backtrack(cur , i + 1 , target - candidates[i]);
        cur.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])i++;
        backtrack(cur , i + 1 , target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        this->candidates = candidates;
        vector<int>cur;
        backtrack(cur , 0 , target);
        return sols;
    }
};
