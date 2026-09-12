#* 390396365	Sep/12/2026 17:00UTC+7	Minh4893IT	1761A - Two Permutations	PyPy 3-64	Accepted	125 ms	

def solve():
    n, a, b = map(int, input().split())

    if a == b and b == n:
        print("YES")
        return

    print("YES" if n - max(a, b) - min(a, b) >= 2 else "NO")

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

