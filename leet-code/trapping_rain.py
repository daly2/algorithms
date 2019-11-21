class Solution:
    def trap(self, height: List[int]) -> int:
        up_to = []
        down_to = []
        current = 0
        for i in range(0, len(height)-1):
            if height[i] > current:
                current = height[i]
            up_to.append(current)
        current = 0
        for i in range(len(height)-1, 0, -1):
            if height[i] > current:
                current = height[i]
            down_to.append(current)
        down_to = down_to[::-1]
        total = 0
        for i in range(0, len(height)-1):
            current_max = min(up_to[i], down_to[i])
            total += max(current_max-height[i], 0)
        return total