class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        """sub_arrays is a dictionary of:
                key = num,
                val = [degree, start_index, end_index]"""
        sub_arrays = {}
        max_degree = 0
        max_degree_elements = []
        for i,num in enumerate(nums):
            if num not in sub_arrays.keys():
                """Create new entry of degree 1 with start and
                   end index both 'i' """
                sub_arrays[num] = [1, i, i]
            else:
                """Increment degree and move end_index to 'i' """
                sub_arrays[num][0] += 1
                sub_arrays[num][2] = i
                
            """Set new max degree and clear current max_degree list"""
            if sub_arrays[num][0] > max_degree:
                max_degree = sub_arrays[num][0]
                max_degree_elements = []
            
            """If this element is equal to max degree,
                add key (num) to list"""
            if sub_arrays[num][0] == max_degree:
                max_degree_elements.append(num);
        
        """Go through list of keys that have max degree 
            and find min sub-array len."""
        min_len = 100000
        for num in max_degree_elements:
            curr_len = sub_arrays[num][2] - sub_arrays[num][1] + 1
            if curr_len < min_len:
                min_len = curr_len
                
        return min_len
