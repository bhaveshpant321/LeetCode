class Solution {
    bool canShip(int load, int days, vector<int>& weights){
        int d=1;
        int curr=0;
        for(int i=0; i<weights.size(); i++){
            if(curr+weights[i]<= load){
                curr+=weights[i];
            }else{
                curr=weights[i]; d++;   // must carry over the weight
            }
        }
        return d<=days? true: false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // ith package: weight[i], cannot load more than maximum capacity
        // todo: least weight capacity of ship that will result in all package being shipped in d days
        // Binary search on answer space: min capacity= size of biggest shipment, max capacity= sum
        int mini=0, maxi=0;
        for(int w: weights){
            maxi+=w;
            mini= max(mini, w);
        }

        int res=maxi;
        while(mini<= maxi){
            int mid= mini+ (maxi-mini)/2;
            if(canShip(mid, days, weights)){
                res= mid;
                maxi= mid-1;
            }else{
                mini= mid+1;
            }
        }
        return res;
    }
};