a=[min(c, str(9-int(c)))for c in input()];print((a[0]if a[0]>'0'else'9')+''.join(a[1:]))