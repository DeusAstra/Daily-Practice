# leetcode-week488 solution report

## T1
2k

## T2
2k

## T3
fw C语言，我将加入更权威的C++
主要在于在l，r蠕动过程中取出区间内部的最大最小值，用C和简单插入删除爆了
所以后面转C++用multiset（红黑树实现）
好吧写完了想起来其实用 C语言 + 线段树 也可以写，但是空间占用高，而且写得复杂
有人（榜一大佬）用的python deque?
```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        max_deque = deque()
        min_deque = deque()
        left = 0
        ans = 0
        
        for right in range(n):
            while max_deque and nums[max_deque[-1]] <= nums[right]:
                max_deque.pop()
            max_deque.append(right)
            
            while min_deque and nums[min_deque[-1]] >= nums[right]:
                min_deque.pop()
            min_deque.append(right)
            
            while (nums[max_deque[0]] - nums[min_deque[0]]) * (right - left + 1) > k:
                if max_deque[0] == left:
                    max_deque.popleft()
                if min_deque[0] == left:
                    min_deque.popleft()
                left += 1
            
            ans += right - left + 1
        
        return ans
```

## T4
不会喵