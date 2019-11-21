class Solution:
    def reverse(self, x: int) -> int:
        x_2 = str(x)
        x_3 = x_2[::-1]
        if x_3[-1] == "-":
            x_3 = "-" + x_3[0:-1]
        x_3 = int(x_3)
        
        if x_3 > 2**31-1 or x_3 < -2**31:
            x_3 = 0
        return x_3