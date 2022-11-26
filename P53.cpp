class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int answer = nums[0];

        // Basically use the solution to Problem 121, but applied to the virtual array S of length n + 1 for the prices
        // where S[j] = nums[0] + ... + nums[j - 1] is the prefix sum for the nums array.

        // int j = 0;
        int S_j = 0;             // To store prefix sum S[j], when j = 0, this is empty sum so we initialize to 0
        int min_S_before_j = 0;  // Minimum amongst all prefix sums S[i] where i < j

        for(int j = 1; j <= n; j++) {
            S_j = S_j + nums[j - 1];

            auto max_sum_subarray_ending_at_j = S_j - min_S_before_j;

            if (max_sum_subarray_ending_at_j > answer)
                answer = max_sum_subarray_ending_at_j;

            if (S_j < min_S_before_j) // Update the min before moving on to j + 1
                min_S_before_j = S_j;
        }

        return answer;
    }
};
