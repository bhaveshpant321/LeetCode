class Solution {
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_to_id;
        unordered_map<string, string> email_to_name;
        int id = 0;

        // 1. Assign unique IDs to every unique email & map name to ALL emails
        for (const auto& acc : accounts) {
            const string& name = acc[0];
            for (size_t j = 1; j < acc.size(); ++j) {
                if (!email_to_id.count(acc[j])) {
                    email_to_id[acc[j]] = id++;
                }
                email_to_name[acc[j]] = name; // Every email gets the name
            }
        }

        // 2. Initialize parent strictly to size = id
        parent.resize(id);
        iota(parent.begin(), parent.end(), 0);

        // 3. Union emails within the same account
        for (const auto& acc : accounts) {
            if(acc.size()< 2) continue; // skip through empty accounts
            int first_id = email_to_id[acc[1]];
            for (size_t j = 2; j < acc.size(); ++j) {
                unite(first_id, email_to_id[acc[j]]);
            }
        }

        // 4. Group emails by root representative
        unordered_map<int, vector<string>> groups;
        for (const auto& [email, email_id] : email_to_id) {
            groups[find(email_id)].push_back(email);
        }

        // 5. Format output
        vector<vector<string>> res;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(email_to_name[emails[0]]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }

        return res;
    }
};