#* 390393297	Sep/12/2026 16:26UTC+7	Minh4893IT	A - Walking Master	PyPy 3	Accepted	203 ms	7400 KB

def solve():
    a, b, c, d = map(int, input().split())

    diff_x = c - a
    diff_y = d - b

    if diff_y < 0:
        print(-1)
        return

    if diff_y < diff_x:
        print(-1)
        return

    print(2 * diff_y - diff_x)


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

