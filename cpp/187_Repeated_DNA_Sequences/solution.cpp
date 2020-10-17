class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n <= 10) return {};
        
        unordered_map<string, int> umap;
        vector<string> res;
        for(int i = 0; i <= n - 10; i++)
        {
            string temp = s.substr(i, 10);
            umap[temp]++;
            
            if(umap[temp] == 2)
                res.push_back(temp);
        }
        return res;
    }
};
