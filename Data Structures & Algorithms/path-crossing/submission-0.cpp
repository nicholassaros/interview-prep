struct Position {
    int x, y;

    bool operator==(const Position&) const = default;
};

struct Hash {
    size_t operator()(const Position& p) const noexcept {
        return std::hash<int>()(p.x) * 31 + std::hash<int>()(p.y);
    }
};

class Solution {
public:
    bool isPathCrossing(string path) {
        std::unordered_set<Position, Hash> _set;
        Position curPos(0,0);
        _set.insert(curPos);

        for(const auto& direction : path) {

            int new_x = curPos.x;
            int new_y = curPos.y;

            switch(direction){
                case 'N':
                    new_y++;
                    break;

                case 'S':
                    new_y--;
                    break;

                case 'E':
                    new_x++;
                    break;

                case 'W':
                    new_x--;
                    break;
            }

            curPos = Position(new_x, new_y);
            std::cout << curPos.x << curPos.y << std::endl;
            if(_set.contains(curPos)) {
                return true;
            }
            _set.insert(curPos);
        }
        return false;
    }
};


/*
Track coords in a set as we move either direction

If we have an occurance in the set we return True since paths have crossed

*/