def solve():
    n = int(input())
    arr = list(map(int, input().split()))

    print(max(arr) * n)

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

