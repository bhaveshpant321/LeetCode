class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // What the question asks: we need to pick subarrays starting from beginning and starting from end in such a way that total elements equate to k and sum is maximized, so what if we instead pick a single substring from middle of size n-k with minimum sum
        int maxScore= 0;
        int total=0;
        for(int x: cardPoints){
            total+=x;
        }

        int size= cardPoints.size()-k;

        // base case: entire array
        if(size==0) return total;
        int window_sum=0;
        for(int i=0; i<size; i++){
            window_sum+=cardPoints[i];
        }
        int min_sum= window_sum;

        for(int i=size; i<cardPoints.size(); i++){
            window_sum+=cardPoints[i];
            window_sum-=cardPoints[i-size];
            min_sum= min(min_sum, window_sum);
        }

        return total-min_sum;
    }
};