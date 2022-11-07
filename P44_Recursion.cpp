class Solution {
public:
    // Generalization: Match the substring of s starting from i (usually denoted by s[i:])
    // with the subpattern of p starting from j (again, this is denoted by p[j:]).
    bool isMatch(string s, int i, string p, int j) {
        // Base case: empty pattern
        if (j == p.length())
            return i == s.length();
 
        // Recursion: reduce the pattern by 1 character
        switch (p[j]) {
            case '?':
                // Match the i-th character of s with the ? and p[j+1:] with the s[i+1:]
                return isMatch(s, i + 1, p, j + 1);
 
            case '*':
                // Try all possible ways to match * with a substring from s[i:k)
                for(int k = i; k <= s.length(); k++)
                    if (isMatch(s, k, p, j + 1))
                        return true;
                return false;
 
            default:
                // p[j] is a single letter [a-z]
                return s[i] == p[j] && isMatch(s, i + 1, p, j + 1);
        }
    }

    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};
