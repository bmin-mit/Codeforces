#* 390395992	Sep/12/2026 16:55UTC+7	Minh4893IT	1766A - Extremely Round	PyPy 3-64	Accepted	93 ms	2800 KB

def solve():
    n = int(input())

    res = 0
    while n >= 10:
        res += 9
        n //= 10

    print(res + n)


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

