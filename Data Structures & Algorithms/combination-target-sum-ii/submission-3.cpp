class Solution {
public:
    vector<int> candidates;
    vector<vector<int> > sols;
    void backtrack(vector<int>&cur , int i , int target){
        if(target == 0){
            if(sols.empty() || sols.back().size() != cur.size())sols.push_back(cur);
            else{
                int matched = 1;
                for(int i = 0 ; i < cur.size() ; i++){
                    if(sols.back()[i] != cur[i]){
                        matched = 0;
                        break;
                    }
                }
                if(matched == 0)sols.push_back(cur);
            }    
                return;
        }
        if(i == candidates.size())return;
        if(target < 0)return;
        cur.push_back(candidates[i]);
        backtrack(cur , i + 1 , target - candidates[i]);
        cur.pop_back();
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
