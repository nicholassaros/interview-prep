class Solution {
public:

    string s;
    map<int,int> cache;

    int dfs(int index) {
        if(cache.contains(index)) { return cache[index]; }
        if(index == s.size()) { return 1; }
        if(s[index] == '0') { return 0; }

        int res = dfs(index + 1);
        if(index < s.size()-1) {
            if(s[index] == '1' ||
            s[index] == '2' && s[index+1] < '7') {
                res += dfs(index+2);
            }
        }
        cache[index] = res;
        return res;
    };



    int numDecodings(string _s) {
        s = _s;
        return dfs(0);
    }
};
