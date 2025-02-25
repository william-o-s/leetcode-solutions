# this problem is a great example as to why dynamic memory exists
# life is just so much easier when you don't have to fit all memory needed in at compile-time

class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        # this splits by consecutive spaces
        raw_words = s.split()
        return ' '.join(reversed(raw_words))
