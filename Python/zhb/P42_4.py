from math import *
a, b, c = map(float, input().split())
p = (a + b + c) / 2
print("%.2f" %(sqrt(p * (p - a) * (p - b) * (p - c))))