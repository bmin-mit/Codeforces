def solve():
    a = int(input())
    print("First" if a % 3 else "Second")

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

