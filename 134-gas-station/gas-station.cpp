class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // start from random index (here, 0 index), if gas becomes negative at any place, start from next
        int n= gas.size();
        int total= 0;   // gas-cost
        int surplus= 0; // tank
        int start=0;
        for(int i=0; i<n; i++){
            total+=gas[i]- cost[i];
            surplus+= gas[i]-cost[i];
            if(surplus<0){
                surplus=0;
                start=i+1;
            }
        }
        return total<0? -1: start;
    }
};