#* 365494834	Mar/05/2026 23:08UTC+7	Minh4893IT	C - Monitor	PyPy 3-64	Accepted	78 ms	0 KB

a, b, x, y = map(int, input().split())

g = __import__('math').gcd(x, y)
x //= g
y //= g

val = min(a // x, b // y)
print(x * val, y * val)