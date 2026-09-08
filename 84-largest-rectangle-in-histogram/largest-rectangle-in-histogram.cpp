class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // How wide can a rectangle of height h expand horizontally?
        // It can expand left until it hits a bar strictly shorter than h
        // Similarly for right
        // Let left[i] and right[i] be indices of first bars that are strictly shorter than current
        // Width= right[i]- left[i] ((right-1)-(left+1)+1)
        // Area[i]= width* heights[i]
        // Approach: Monotonic increasing stack
        // Two sentinel padding trick: Append a 0 at the end and treat index -1 with height 0 as start

        int n= heights.size();
        stack<int> st;
        int max_area=0;

        // Iterate upto n
        for(int i=0; i<=n; i++){
            int currHeight= (i==n)? 0: heights[i];
            // whenever curr is shorter than bar at the top of the stack, we have found the right boundary for the current top
            while(!st.empty() && currHeight< heights[st.top()]){
                int h= heights[st.top()];
                st.pop();

                int left_boundary= (st.empty())? -1: st.top();  // if stack is empty it was the first element
                int w= i-left_boundary-1;
                max_area= max(max_area, h*w);
            }
            st.push(i);
        }
        return max_area;
    }
};