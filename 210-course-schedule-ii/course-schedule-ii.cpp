class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list graph and compute in-degrees
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            // Direction: prerequisite -> course
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }
        
        // Step 2: Push all courses with 0 in-degree into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Process the courses level by level
        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            
            // Reduce the in-degree of all neighboring dependent courses
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                // If a neighbor has no more prerequisites, add it to the queue
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: Check if we were able to include all courses
        // If order size matches numCourses, it means no cycle was found
        if (order.size() == numCourses) {
            return order;
        }
        
        // Cycle detected, impossible to complete all courses
        return {};
    }
};
