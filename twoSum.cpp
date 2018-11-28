/*
 * Test 2
 * 暴力解法：Runtime: 76 ms, faster than 39.33% of C++ online submissions for Two Sum.
 * 时间复杂度 O(n^2)
 */

class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target)
    {
        // get vector size
        int nSize = nums.size();
        for (int i = 0; i < nSize-1; ++i)
        {
            for (int j = i+1; j < nSize; ++j)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        
        // can't find target
        return {};
    }
};

/*
 * Test 1
 * 该解法在 target 的值在数组中某两个和之间的情况下会无限循环，目前还没想到好的处理方法
 * 时间复杂度可能是 O((n^2)/2)，相当于 O(n^2)
 */

#if 0
class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target)
    {
        // get array's size
        int nSize = nums.size();
        // invalid parameter
        if (nSize < 2)
            return {};
        
        // try sum two numbers for target
        int nTail = nSize / 2;
        int nHead = nTail - 1;
        while (nHead != nTail)
        {
            int nSum = nums[nHead] + nums[nTail];
            // get target
            if (nSum == target)
            {
                return {nHead, nTail};
            }
            // sum less than target
            else if (nSum < target)
            {
                if (nTail != (nSize-1))
                    ++nTail;
                else
                    ++nHead;
            }
            // sum greater than target
            else if (nSum > target)
            {
                if (nHead != 0)
                    --nHead;
                else
                    --nTail;
            }
        }
        
        // can't find target
        return {};
    }
};
#endif
