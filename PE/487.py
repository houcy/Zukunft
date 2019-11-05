def F(m, n, p):
	f = [0] * (m + 3)
	for i in range(1, m + 3):
		f[i] = (f[i - 1] + pow(i, m, p)) % p
	for i in range(1, m + 3):
		f[i] = (f[i] + f[i - 1]) % p		
	for i in range(1, m + 3):
		for j in range(i, m + 3)[::-1]:
			f[j] = (f[j] - f[j - 1]) % p
	t = 1
	z = 0
	for i in range(m + 3):
		z = (z + t * f[i]) % p
		t = t * (n - i) * pow(i + 1, p - 2, p) % p
	return z

primes = [2000000011, 2000000033, 2000000063, 2000000087, 2000000089, 2000000099, 2000000137, 2000000141, 2000000143, 2000000153, 2000000203, 2000000227, 2000000239, 2000000243, 2000000269, 2000000273, 2000000279, 2000000293, 2000000323, 2000000333, 2000000357, 2000000381, 2000000393, 2000000407, 2000000413, 2000000441, 2000000503, 2000000507, 2000000531, 2000000533, 2000000579, 2000000603, 2000000609, 2000000621, 2000000641, 2000000659, 2000000671, 2000000693, 2000000707, 2000000731, 2000000741, 2000000767, 2000000771, 2000000773, 2000000789, 2000000797, 2000000809, 2000000833, 2000000837, 2000000843, 2000000957, 2000000983, 2000001001, 2000001013, 2000001043, 2000001049, 2000001089, 2000001097, 2000001103, 2000001109, 2000001119, 2000001127, 2000001137, 2000001149, 2000001151, 2000001167, 2000001173, 2000001187, 2000001229, 2000001233, 2000001247, 2000001257, 2000001277, 2000001287, 2000001349, 2000001359, 2000001379, 2000001413, 2000001457, 2000001511, 2000001517, 2000001527, 2000001539, 2000001551, 2000001557, 2000001583, 2000001599, 2000001623, 2000001629, 2000001649, 2000001677, 2000001727, 2000001743, 2000001821, 2000001833, 2000001851, 2000001881, 2000001929, 2000001953, 2000001973]
print F(4, 100, 2 ** 521 - 1)
s = 0
for p in primes:
	print p
	s += F(10000, 10 ** 12, p)
print s