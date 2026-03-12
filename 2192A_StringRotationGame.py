def countGroup(s):
    return sum(s[i] != s[i + 1] for i in range(len(s) - 1)) + 1

def solve():
    n = int(input())
    s = input()

    res = 0
    for i in range(n):
        curr = s[i:] + s[:i]
        res = max(res, countGroup(curr))
    print(res)


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

