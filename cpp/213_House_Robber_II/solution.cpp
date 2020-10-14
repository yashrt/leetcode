class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0];
        vector<int> choice1(nums.begin(), nums.end()-1);   
        vector<int> choice2(nums.begin() + 1, nums.end());
        return max(house_robber(choice1), house_robber(choice2));
    }

    int house_robber(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i=2; i<=nums.size(); i++)
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);

        return dp.back();
    }
};
