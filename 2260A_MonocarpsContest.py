def solve():
    n = int(input())
    lst = list(map(int, input().split()))

    if lst.count(0) < 2:
        print("-1")
        return

    print(2 - (1 - lst[0]) - (1 - lst[-1]))

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

