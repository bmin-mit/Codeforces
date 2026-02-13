def solve():
    n = int(input())

    res = 0
    for i in range(n, n + 1000):
        if i - sum(int(c) for c in str(i)) == n:
            res += 1
    print(res)

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

