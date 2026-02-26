def solve():
    a, b = map(int, input().split())

    val = a - 2 * b
    k = val // 6
    print("YES" if val >= 0 and val % 3 == 0 and a > b and k + b >= 0 else "NO")

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

