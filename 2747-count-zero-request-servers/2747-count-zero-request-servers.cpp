class Solution {
public:
    static int comp(vector<int>& a , vector<int>& b){
        return a[1] < b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int q = queries.size();
        vector<int>res(q);
        sort(logs.begin(),logs.end(),comp);
        vector<pair<int,int>>queriesInd;
        for(int i = 0 ; i < q ; i++){
            queriesInd.push_back({queries[i],i});
        }
        //these two would be pointing towards the logs
        int i = 0 ;
        int k = 0 ;
        map<int ,int>mpp;
        sort(queriesInd.begin(),queriesInd.end());
        for(int j = 0 ; j < q ; j++){
            //these two would provide range towards the array
            // int count = 0;
            int startInd = queriesInd[j].first - x ;
            int endInd = queriesInd[j].first;
            int Ind = queriesInd[j].second;

            //include the range -->
            while(k < m && logs[k][1] <= endInd){
                mpp[logs[k][0]]++;
                k++;
            }
            //shrink till the startInd;
            while(i < m && logs[i][1] < startInd){
                int server = logs[i][0];
                --mpp[server];

                if (mpp[server] == 0) {
                    mpp.erase(server);
                }
                ++i;
            }
            int count = n - mpp.size();
            res[Ind] = count;
        }
        return res;
    }
};