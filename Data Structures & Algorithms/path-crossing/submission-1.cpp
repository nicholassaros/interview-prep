class Solution {
public:
    bool isPathCrossing(string path) {

        std::set<std::pair<int,int>> coordMap;

        std::pair<int,int> currentPosition = std::make_pair(0,0);
        coordMap.insert(currentPosition);

        for(const auto& direction : path) {

            if(direction == 'N') {
                currentPosition = {currentPosition.first + 1, currentPosition.second};

            } else if (direction == 'S') {
                currentPosition = {currentPosition.first - 1, currentPosition.second};

            } else if (direction == 'E') {
                currentPosition = {currentPosition.first, currentPosition.second + 1};
            } else {
                currentPosition = {currentPosition.first, currentPosition.second - 1};
            }

            if(coordMap.contains(currentPosition)) {
                return true;
            }
            coordMap.insert(currentPosition);

        }

        return false;
    }
};


/*

Morgans first intuition 
- Hashmap (or array or vector)

How can we track a point we have been on

- Loop over the input string
- Translate current coordinate position
- Check hashmap for existance of coordinate
    - If in hashMap we return True

- Add position to hashMap (1,0)

- If loop through whole string return false

*/