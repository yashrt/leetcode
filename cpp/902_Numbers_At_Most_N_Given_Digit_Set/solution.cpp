class Solution {
public:
    int help(string num, int i, vector<string>& digits)
    {
        int ans = 0;
        if (i >= num.size())
            return 0;
        string ch = num.substr(i, 1);
        int lower = lower_bound(digits.begin(), digits.end(), ch) - digits.begin();
        ans = lower * (pow(digits.size(), num.size()-i-1));

        if(ch==digits[lower])
        {
            if (i == num.size()-1)
                ans += 1;
            ans += help(num, i+1, digits);
        }
        return ans;  
    }
     
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int x = digits.size();
        int y = log10(n);
        int ans = 0;
        if (x != 1)
        {
            ans = (x*(pow(x,y) - 1))/(x-1);   
            string num = to_string(n);
            ans += help(num, 0, digits);
            return ans;
        }    
        else 
        {
            char ch = to_string(n)[0];
            ans += y;
            return (digits[0][0] <= ch) ? ans+1 : ans;
        }   
    }
};
