class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        current_max_num = 0
        current_max_fre = 0
        d = {}
        for n in nums:
            """Create frequency table"""
            if n in d.keys():
                d[n] += 1
            else:
                d[n] = 1
                
            """Track max along the way"""
            if d[n] > current_max_fre:
                current_max_num = n
                current_max_fre = d[n]

        return current_max_num
