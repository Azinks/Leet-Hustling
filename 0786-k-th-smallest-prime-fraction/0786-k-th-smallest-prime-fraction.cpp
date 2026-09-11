class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        if(n < 3) return {arr[0],arr[1]};
        priority_queue <pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;
        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {
                double value = (double)arr[i] / arr[j];
                pq.push({value,{i,j}});
            }
        }
        while(k>1){
            pq.pop(); 
            k--;
        }
        auto top = pq.top();
        return {arr[top.second.first],arr[top.second.second]};
    }
};