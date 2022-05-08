'''
题意：给定一个数组，每个位置的元素代表你在该位置可以跳跃的最大长度，问你是否能跳到最后一个下标
思路：破题关键：你能跳到的范围一定是连续的，如果你能跳到i 你一定能跳到[0,i-1]
    所以0开始从前往后遍历，每个位置求能跳到的最大值，再取最大就好了
'''

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        res=nums[0]
        n=len(nums)
        for i in range(n):
            if(i<=res):
                res=max(res,i+nums[i])
        return res >= n-1