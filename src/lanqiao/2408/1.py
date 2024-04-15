import os
import sys

ans = 0

for year in range(1900, 10000):
    for month in range(1, 13):
        if month in [1, 3, 5, 7, 8, 10, 12]:
            day_max = 31
        if month in [4, 6, 9, 11]:
            day_max = 30
        if month == 2:
            if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
                day_max = 29
            else:
                day_max = 28
        for day in range(1, day_max):
            x = 0
            for i in map(int, str(year)):
                x = x + i
            y = 0
            for i in map(int, str(day) + str(month)):
                y = y + i
            if x == y:
                ans = ans + 1
print(ans)
