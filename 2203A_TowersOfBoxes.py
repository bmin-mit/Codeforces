def solve():
    n, m, d = map(int, input().split())

    h = d // m + 1
    print((n + h - 1) // h)

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

