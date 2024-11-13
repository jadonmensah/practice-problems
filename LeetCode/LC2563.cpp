// Written in LeetCode's online IDE
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        long long i = 1;
        sort(nums.begin(), nums.end());
        for (const int& num : nums) {
            sum += distance(lower_bound(nums.begin()+i, nums.end(), lower-num),
                            upper_bound(nums.begin()+i, nums.end(), upper-num));
            i++;
        }
        return sum;
    }
};
