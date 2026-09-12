#* 390397227	Sep/12/2026 17:10UTC+7	Minh4893IT	1883B - Chemistry	PyPy 3-64	Accepted	203 ms	7800 KB

from collections import Counter

def solve():
    n, k = map(int, input().split())
    s = input()

    c = Counter(s)
    odd = sum(count % 2 for count in c.values())

    print("YES" if odd - 1 <= k else "NO")

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

