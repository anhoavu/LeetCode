class Solution {
public:
    bool isMatch(string s, string p) {
        auto ls = s.length();
        auto lp = p.length();

        vector<vector<bool>> M(lp + 1, vector<bool>(ls + 1, false));

        // To make things fast when matching wildcard, we also keep track of accumulation
        // A[j][i] := M[j][i] || M[j][i+1] || ... || M[j][ls]
        vector<vector<bool>> A(lp + 1, vector<bool>(ls + 1, true));

        // Base case j = lp, we have
        //     M[lp][i] = true only if i == ls  (empty pattern can only match empty string).
        // Note that we do not need a loop here given the construction of M initializes all
        // entries to false. This implies A[lp][i] = true for all i, again no loop is needed
        // due to vector initialization.
        M[lp][ls] = true;

        // Filling the tables
        for(int j = lp - 1; j >= 0; j--) {
            for(int i = ls; i >= 0; i--) {
                switch (p[j]) {
                    case '?':
                        M[j][i] = (i < ls) && M[j + 1][i + 1];
                        break;

                    case '*':
                        // for(int k = i; k <= ls; k++) {
                        //     M[j][i] = M[j][i] || M[j + 1][k];
                        // }
                        M[j][i] = A[j + 1][i];
                        break;

                    default: // p[j] is a single letter in [a-z]
                        M[j][i] = (i < ls) && s[i] == p[j] && M[j + 1][i + 1];
                        break;
                }

                A[j][i] = (i == ls ? M[j][i] : (M[j][i] || A[j][i + 1]));
            }
        }

        return M[0][0];
    }
};

