class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_str = str(x)
        if len(x_str)%2:
            x_first = x_str[:len(x_str)//2]
            x_last = x_str[len(x_str)//2+1:]
            x_last_rev = x_last[::-1]
            return (x_first == x_last_rev)
        x_first = x_str[:len(x_str)//2]
        x_last = x_str[len(x_str)//2:]
        x_last_rev = x_last[::-1]
        return (x_first == x_last_rev)