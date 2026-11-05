class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1,
                             vector<int>& arr2, int d) {

        int res = 0;

        sort(arr2.begin(), arr2.end());

        for(int a : arr1) {

            int low = 0;
            int high = arr2.size() - 1;

            bool found = false;

            while(low <= high) {

                int mid = low + (high - low) / 2;

                if(arr2[mid] >= a - d &&
                   arr2[mid] <= a + d) {

                    found = true;
                    break;
                }
                else if(arr2[mid] < a - d) {

                    low = mid + 1;
                }
                else {

                    high = mid - 1;
                }
            }

            if(!found) {
                res++;
            }
        }

        return res;
    }
};