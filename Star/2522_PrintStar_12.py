sizeOfLines = int(input())
SPACE = ' '
STAR = '*'

for i in range(2 * sizeOfLines - 1):
	if i < sizeOfLines:
		for j in range(sizeOfLines - (i + 1)):
			print(SPACE, end='')
		for j in range(i + 1):
			print(STAR, end='')
		print()
	else:
		for j in range(i - sizeOfLines + 1):
			print(SPACE, end='')
		for j in range(sizeOfLines - (i - sizeOfLines + 1)):
			print(STAR, end='')
		if not i == 2 * sizeOfLines - 2: print()