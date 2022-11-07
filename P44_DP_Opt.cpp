class Solution {
public:
    bool isMatch(string s, string p) {
        auto ls = s.length();
        auto lp = p.length();

        vector<vector<bool>> M(2, vector<bool>(ls + 1, false));
        vector<vector<bool>> A(2, vector<bool>(ls + 1, true));
        M[lp % 2][ls] = true;

        for(int j = lp - 1; j >= 0; j--) {
            auto rj = j % 2;
            auto rjp1 = 1 - rj;
            switch (p[j]) {
                case '?':
                    M[rj][ls] = false;
                    for(int i = ls - 1; i >= 0; i--) {
                        M[rj][i] = M[rjp1][i + 1];
                    }
                    break;

                case '*':
                    M[rj][ls] = M[rjp1][ls];
                    for(int i = ls - 1; i >= 0; i--) {
                        M[rj][i] = A[rjp1][i];
                    }
                    break;

                default:
                    M[rj][ls] = false;
                    for(int i = ls - 1; i >= 0; i--) {
                        M[rj][i] = s[i] == p[j] && M[rjp1][i + 1];
                    }
                    break;
            }

            A[rj][ls] = M[rj][ls];
            for(int i = ls - 1; i >= 0; i--) {
                A[rj][i] = M[rj][i] || A[rj][i + 1];
            }
        }

        return M[0][0];
    }
};

