class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> umap;
        int m = arr.size();
        for (int i = 0; i < pieces.size(); i++)
            umap[pieces[i][0]] = i;
        
        for (int i = 0; i < m; )
        {
            if (umap.find(arr[i]) == umap.end())
                return false;
            else 
            {
                int j = umap[arr[i]];
                int n = pieces[j].size();
                if (n > m - i)
                    return false;
                else {
                    for (int k = 0; k < n; k++)
                    {
                        if (pieces[j][k] == arr[i])
                            i++;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
