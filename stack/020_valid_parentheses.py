class Solution:
    def isValid(self, s: str) -> bool:
        stack: list[str] = []
        crct: dict[str, str] = {"(": ")", "{": "}", "[": "]"}

        for c in s:
            if c in crct:
                stack.append(c)
            else:
                if not stack:
                    return False
                if crct[stack.pop()] != c:
                    return False

        return not stack
