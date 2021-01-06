class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> num(2000, false);
        for (int i: arr) {
            num[i-1] = true;
        }
        int i;
        for (i = 0; i < 2000 && k; i++)
        {
            if(!num[i])
                k--;
        }
        return i;
    }
};
