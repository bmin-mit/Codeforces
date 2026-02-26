

def solve():
    s = list(map(int, input()))
    if sum(s) < 10:
        print(0)
        return
    
    case1 = 0
    sum1 = sum(s)
    backup = s.copy()

    while sum1 >= 10:
        case1 += 1
        maxChar = max(s[1:])
        maxIndex = s[1:].index(maxChar)
        s[maxIndex + 1] = 0

        sum1 -= maxChar

    s = backup
    s[0] = 1
    sum2 = sum(s)
    case2 = 1
    while sum2 >= 10:
        case2 += 1
        maxChar = max(s[1:])
        maxIndex = s[1:].index(maxChar)
        s[maxIndex + 1] = 0

        sum2 -= maxChar

    print(min(case1, case2))

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()

