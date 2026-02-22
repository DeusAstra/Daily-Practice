class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int gamer = 0;
        int score[2];
        score[0] = score[1] = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            if(i % 6 == 5) {
                gamer ^= 1;
            }
            if(nums[i] % 2 == 1) {
                gamer ^= 1;
            }
            score[gamer] += nums[i];
        }
        return score[0]-score[1];
    }
};