class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        
        int n = matrix[0].size();
        if(n==0 || target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;
        
        int low = 0;
        int high = m - 1;
        int mid;
        while(high >= low)
        {
            mid = (low + high) / 2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target)
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            else if(target < matrix[mid][0])
                high = mid - 1;
            else
                low = mid + 1;
                
        }
        return false;
        
    }
};
