class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>traverse_arr;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                traverse_arr.push_back(matrix[i][j]);
            }
        }
        sort(traverse_arr.begin(),traverse_arr.end());
        int high = traverse_arr.size() - 1;
        int start = 0;
        while(start <= high){
            int mid = start + (high - start) / 2;
            if(mid == k - 1){
                return traverse_arr[mid];
            }
            if(mid < k){
                start = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};