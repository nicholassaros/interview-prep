class Solution {
public:

    struct Group {
        int start;
        int end;
    };

    int maxLengthBetweenEqualCharacters(string s) {
        

        std::unordered_map<char, Group> charMap;
        int result = -1;

        for(int i = 0; i< s.size(); i++) {
            if(!charMap.contains(s[i])) {
                charMap[s[i]] = Group(i, -1);
            } else {
                charMap[s[i]].end = i;
            }
        }

        for(auto& [c, group] : charMap) {
            if(group.end == -1) { continue; }

            result = max(result, group.end - group.start -1);
        }



        return result;
    }
};