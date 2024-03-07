#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            // pairs = (nums[i], target - nums[i])
            // 如果pairs[1]在hashMap中,说明pairs[0]已经被添加过了，pairs[0]应该在pairs[1]前面
            if (hashMap.count(target - nums[i]) > 0)
            {
                ans[0] = hashMap[ target - nums[i] ];
                ans[1] = i;
                return ans;
            }
            // 如果没有，存到hashMap中
            hashMap[ nums[i] ] = i;
        }

        // 如果都存到hashMap中还是没有在循环中return, 说明没有
        return ans;      
    }
};