class Solution {
public:

    bool solve(string s1, string s2, unordered_map<string, bool>& mpp) {

        // Same string
        if (s1 == s2)
            return true;

        // Length 1 and different
        if (s1.length() <= 1)
            return false;

        string key = s1 + "_" + s2;

        // Already calculated
        if (mpp.find(key) != mpp.end())
            return mpp[key];

        // Character frequency check
        vector<int> freq(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0)
                return mpp[key] = false;
        }

        int n = s1.length();

        for (int i = 1; i < n; i++) {

            // Case 1: No swap
            bool not_swapped =
                solve(s1.substr(0, i),
                      s2.substr(0, i),
                      mpp)
                &&
                solve(s1.substr(i, n - i),
                      s2.substr(i, n - i),
                      mpp);

            // Case 2: Swap
            bool swapped =
                solve(s1.substr(0, i),
                      s2.substr(n - i, i),
                      mpp)
                &&
                solve(s1.substr(i, n - i),
                      s2.substr(0, n - i),
                      mpp);

            if (not_swapped || swapped)
                return mpp[key] = true;
        }

        return mpp[key] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.length() != s2.length())
            return false;

        unordered_map<string, bool> mpp;

        return solve(s1, s2, mpp);
    }
};