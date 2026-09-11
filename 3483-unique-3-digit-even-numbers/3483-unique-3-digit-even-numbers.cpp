class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            // First digit cannot be 0
            if (digits[i] == 0) continue;

            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    int made = digits[i] * 100
                             + digits[j] * 10
                             + digits[k];

                    // 3-digit and even
                    if (made % 2 == 0) {
                        st.insert(made);
                    }
                }
            }
        }

        return st.size();
    }
};