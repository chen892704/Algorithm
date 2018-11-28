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
