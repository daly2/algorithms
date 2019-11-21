class Solution:
    def maxArea(self, height: List[int]) -> int:
        front = 0
        back = len(height)-1
        area = min(height[front], height[back])*(back-front)
        for i in range(0, len(height)-1):
            if(height[front]>height[back]):
                back-=1
            else:
                front+=1
            current_area = min(height[front]*(back-front), height[back]*(back-front))
            area = max(area, current_area)
        return area