#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        map<int, int> record;

        for (int i = 0; i < nums.size(); ++i) {
            if (record.count(target - nums[i]) > 0) {
                return {record[target - nums[i]], i};
            }
            record[nums[i]] = i;
        }
        return {-1, -1};
    }
};