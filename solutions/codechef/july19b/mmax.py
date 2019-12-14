# Contest JULY19B - Problem MMAX
# https://www.codechef.com/JULY19B/problems/MMAX

t = int(input())
for _ in range(t):
    n = int(input())
    k = int(input())
    k %= n
    k = min(k, n-k)
    k = min(2*k, n-1)
    print(k)
