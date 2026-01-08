from collections import Counter


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        freq: list[int] = [0] * 26
        for c in s:
            freq[ord(c) - ord("a")] += 1
        for c in t:
            freq[ord(c) - ord("a")] -= 1

        for count in freq:
            if count != 0:
                return False

        return True

    # slower
    def isAnagram2(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
