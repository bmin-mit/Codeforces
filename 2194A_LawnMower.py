def solve():
    n, m = map(int, input().split())
    print(n - n // m)


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

