class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>>& res)
    {
        if(target < 0)  
            return;
        if(target == 0) 
            res.push_back(temp);
        
        for(int i=start; i<candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i, temp, res);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(candidates, target, 0, temp, res);
        return res;
    }
};
