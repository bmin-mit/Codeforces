def solve():
    a, b = map(int, input().split())

    if a >= b:
        print("Alice")
        return

    x = 3*a - 2*b
    print("Bob" if x >= 0 else "Alice")

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

