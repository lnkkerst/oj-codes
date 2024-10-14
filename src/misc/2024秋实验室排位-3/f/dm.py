import random

n = int(10)
m = int(10)
k = int(5)

choices = ['A', 'B', 'C', 'D']

def get_not(c):
  res = random.choice(choices)
  while res == c:
    res = random.choice(choices)
  return res

print(n, m, k)

s = ''.join(random.choice(choices) for _ in range(m))

print(s)

def gen_str():
  d = list(range(m))
  random.shuffle(d)
  d = d[:k]
  res = ''
  for i in range(m):
    if i in d:
      res = res + get_not(s[i])
    else:
      res = res + s[i];
  return res

for _ in range(n - 1):
  print(gen_str())