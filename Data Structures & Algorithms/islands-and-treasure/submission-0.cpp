struct Position {
    int _x;
    int _y;
    int _dist;

    Position(int x, int y, int dist)
        : _x(x), _y(y), _dist(dist) {};
};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<Position>                _queue;
        std::set<std::pair<int,int>>        _visited;
        std::vector<std::pair<int, int>>    _moves = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        // get starting positions as position struct in queue
        for(int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {

                if (grid[i][j] == 0) {
                    _queue.push(Position(i,j,0));
                }
            }
        }

        while(!_queue.empty()) { // while the queue is not empty

            int queueSize = _queue.size();
            for(int i = 0; i < queueSize; i++) {
                auto& [_x,_y,_dist] = _queue.front();
                _queue.pop();

                grid[_x][_y] = std::min(grid[_x][_y], _dist);
                _visited.insert(std::make_pair(_x,_y));

                // for all valid positions add back to queue.
                for (const auto& move : _moves) {
                    int newX = _x + move.first;
                    int newY = _y + move.second;

                    if(newX >= 0 && 
                    newX < grid.size() && 
                    newY >= 0 && 
                    newY < grid[0].size() && 
                    grid[newX][newY] != -1 && 
                    _visited.find(std::make_pair(newX, newY)) == _visited.end()) {
                        _queue.push(Position(newX,newY, _dist+1));
                    }
                }
            }
        }

        // for each element in the queue

        // bfs using a ref to the position in the grid
    }
};

// loop through the matrix and add all threasure as starting point

// bfs out from tresure and do a min comparison , avoid all -1 cells

