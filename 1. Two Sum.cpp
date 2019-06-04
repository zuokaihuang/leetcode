class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> ret;
		map<int, int> hashmap;

		int size = nums.size();

		for (int i = 0; i < size; i++)
		{
			int second = target - nums[i];
			if (hashmap.count(second)) {
				ret.push_back(hashmap[second]);
				ret.push_back(i);
				break;
			}
			hashmap[nums[i]] = i;
		}
		return ret;


	}
};