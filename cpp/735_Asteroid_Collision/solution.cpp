class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i =0; i < asteroids.size(); i++)
        {
            if(res.empty())
            {
                res.push_back(asteroids[i]);
            }
            else if ((asteroids[i] > 0 && res.back() > 0) || (asteroids[i] < 0 && res.back() < 0))
            {
                res.push_back(asteroids[i]);
            }
            else if (res.back() < 0 && asteroids[i] > 0)
            {
                res.push_back(asteroids[i]);
            }
            else if (abs(res.back()) > abs(asteroids[i])) 
            {
            }
            else if (abs(res.back()) == abs(asteroids[i])) 
            {
                res.pop_back();
            }
            else 
            {
                res.pop_back();
                --i;
            }
        }
        return res;
    }
};
