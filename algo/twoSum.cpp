class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> freq;

        for(int i=0; i<size; i++){
            int value = target - nums[i];

            if(freq.find(value) != freq.end()){
                return {freq[value],i};
            }
            freq[nums[i]] = i;
        }
        return {};
    }
};
