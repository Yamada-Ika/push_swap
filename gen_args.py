import random

n = int(input())
print(*random.sample(range(0, n+1), n+1))
