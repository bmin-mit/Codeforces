def solve():
    n = int(input())
    l = list(map(int, input().split()))
    print("YES" if 67 in l else "NO")

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

