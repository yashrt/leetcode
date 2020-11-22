class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(string word: words)
        {
            string str = "";
            for(char ch: word)
                str += arr[ch-'a'];
            s.insert(str);
        }
        return s.size();
    }
};
