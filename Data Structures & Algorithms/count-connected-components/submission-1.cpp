class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        map<int,vector<int>> node_map;
        set<int> visited;
        int res = 0;
        // format into adj map

        for(auto& pair : edges){
            node_map[pair[0]].push_back(pair[1]);
            node_map[pair[1]].push_back(pair[0]);
        }

        // loop over all non visited components in adj map

        // if we detect non visited we travese and add all nodes to visited


        for(int i = 0; i < n; i++){

            cout << "Checking node: " << i << endl;
            
            if (visited.count(i) == 0) {
                res++;
                dfs(i, node_map, visited);
            }

        }
        return res;
    }


    void dfs(int node, map<int,vector<int>>& node_map, set<int>& visited){
        if (visited.count(node) > 0){
            return;
        }

        visited.insert(node);
        for(auto& neighbor : node_map[node]){
            dfs(neighbor, node_map, visited);
        }
        return;
    }
};
