def rec(m, x):
	if m >= 1:
		power = 5 ** (m-1)
		location = x // power
		if location == 0 or location == 4:
			return 0;
		elif location == 1 or location == 3:
			return 1 * power + rec (m - 1, x % power)
		elif location == 2:
			return 2 * power + rec (m-1, x % power)
		return maxheightatx
	return 0
a = eval(raw_input())
for i in range(a):
	m, x, y = map (int,raw_input().split())
	if (y < rec(m, x)):
		print "crystal"
	else:
		print "empty"
