class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int max = 0;
        int start = 0;
        for ( int i=0; i < s.size(); i++)
        {
            if (umap.find(s[i]) == umap.end())
            {
                umap[s[i]] = i;
            }
            else {
                int deleteTill = umap[s[i]];
                for (int j = start; j <= deleteTill; j++)
                    umap.erase(s[j]);
                start = deleteTill + 1;
                umap[s[i]] = i;
            }
            if (umap.size() > max)
                max = umap.size();
        }
        return max;
    }
};
