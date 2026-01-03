class Solution(object):
    # bad solution, strings are immutable in python hence result += c
    # and result = result[:-1] create new strings which involve copying
    # all characters.
    # overall time complexity becomes O(n^2) (for loop + string operations)
    def removeDuplicates(self, s: str) -> str:
        result: str = ""
        for c in s:
            if result == "":
                result += c
                continue

            if result[-1] == c:
                result = result[:-1]
            else:
                result += c

        return result

    # use list as stack
    def removeDuplicates2(self, s: str) -> str:
        stack: list[str] = []
        for c in s:
            if stack and stack[-1] == c:
                stack.pop()
            else:
                stack.append(c)

        return "".join(stack)


sol = Solution()
print(Solution.removeDuplicates(sol, "abbaca"))
