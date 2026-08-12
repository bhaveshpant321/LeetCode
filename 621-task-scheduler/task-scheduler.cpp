class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        for(auto t: tasks){
            frequency[t-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            if(frequency[i]) pq.push(frequency[i]);
        }
        int time=0;
        while(!pq.empty()){
            vector<int> remain;
            int cycle= n+1; // after A task, there will be n more tasks, so cooldown period= n+1
            while(cycle && !pq.empty()){
                int max_freq= pq.top();
                pq.pop();
                if(max_freq>1) remain.push_back(max_freq-1);
                time++;
                cycle--;
            }
            for(int count: remain){
                pq.push(count);
            }
            if(pq.empty()) break;
            time+=cycle;
        }
        return time;
    }
};