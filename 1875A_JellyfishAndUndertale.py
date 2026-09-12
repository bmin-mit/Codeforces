#* 390398032	Sep/12/2026 17:19UTC+7	Minh4893IT	1875A - Jellyfish and Undertale	PyPy 3-64	Accepted	171 ms	7400 KB

def solve():
    a, b, n = map(int, input().split())
    print(sum(min(a - 1, int(c)) for c in input().split()) + b)

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

