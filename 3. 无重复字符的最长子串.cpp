#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> rec;
        int l = 0;
        int res = 0;

        for (int i = 0; i < s.size(); ++i) {
            auto it = rec.find(s[i]);
            if (it != rec.end()) {
                if (it->second >= l) {
                    l = it->second + 1;
                }
            }
            res = res > (i - l + 1) ? res : (i - l + 1);
            rec[s[i]] = i;
        }
        return res;
    }
};