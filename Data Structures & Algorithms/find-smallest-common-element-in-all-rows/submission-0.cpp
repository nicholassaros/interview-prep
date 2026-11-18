class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        
        std::vector<std::set<int>> numSetList;


        for(int i = 0; i < mat.size(); i++) {

            numSetList.push_back(std::set<int>{});

            for (int j = 0; j<mat[0].size(); j++) {
                numSetList[i].insert(mat[i][j]);
            }
        }

        for(const auto& num : mat[0]) {
            bool inEverySet = true;

            for(const auto& numSet : numSetList) {
                if (!numSet.contains(num)) {
                    inEverySet = false;
                    break;
                }
            }

            if (inEverySet) {
                return num;
            }
        }

        return -1;
    }
};

/*

Brute force
    Hash all elements in rows 1 -> n
    Loop over first row and ensure each that the element is in all other maps

*/