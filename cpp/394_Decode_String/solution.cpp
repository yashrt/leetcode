class Solution {
public:
    
    string decodeString(string s) {
        stack<int> times;
        stack<string> strStack;
        string num = "";
        string res = "";
        string str = "";
        strStack.push("");
        times.push(0);
        
        for (char ch: s)
        {
            if (isalpha(ch))
                strStack.top() += ch;
            else if (isdigit(ch))
                num += ch;
            else if (ch == '[')
            {
                times.push(stoi(num));
                strStack.push("");
                num = "";
            }
            else if (ch == ']')
            {
                int time = times.top();
                times.pop();
                str = strStack.top();
                strStack.pop();
                for (int i = 1; i <= time; i++)
                    strStack.top() += str;
                str = "";
            }            
        }
        return strStack.top();
    }
};
