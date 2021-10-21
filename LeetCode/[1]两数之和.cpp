//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
//
// 
//
// 示例: 
//
// 给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// 
// Related Topics 数组 哈希表 
// 👍 8773 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
		if(nums.size() <= 1)
			return res;
		unordered_map<int, int> h;
		for(size_t i=0;i<nums.size();++i) {
			if(h[target- nums[i]] > 0){
				res.push_back(h[target- nums[i]] - 1);
				res.push_back(i);
				return res;
			}
			h[nums[i]] = i + 1;
		}
		return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
