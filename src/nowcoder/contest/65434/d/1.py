time1 = input()
time2 = input()

hour1, minute1, second1 = map(int, time1.split(":"))
hour2, minute2, second2 = map(int, time2.split(":"))

total_seconds1 = hour1 * 3600 + minute1 * 60 + second1
total_seconds2 = hour2 * 3600 + minute2 * 60 + second2
time_difference = abs(total_seconds2 - total_seconds1)

print(time_difference)
