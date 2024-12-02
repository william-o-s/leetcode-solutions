'''
Algorithm:

1. Loop over consecutive characters
2. If character is different, store current length and current char
3. Append to last index
4. Repeat

'''

class Solution:
    def compress(self, chars: list[str]) -> int:
        if len(chars) == 1:
            return 1

        lastIndex = 0
        currIndex = 0
        currChar = chars[0]

        for i, char in enumerate(chars):
            
        