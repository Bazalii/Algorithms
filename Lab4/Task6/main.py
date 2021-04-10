def toFixed(numObj, digits=0):
    return f"{numObj:.{digits}f}"
fin = open("garland.in")
fout = open("garland.out", "w")
Input_Array = fin.readline().split()
n = int(Input_Array[0])
A = float(Input_Array[1])
left = 0
right = A
last = -1
while True:
    middle = (left + right) / 2
    if middle == left or middle == right:
        break
    previous = A
    current = middle
    ground = True
    for i in range(2, n):
        next_element = 2 * current - previous + 2
        ground &= next_element > 0
        previous = current
        current = next_element
    if ground:
        right = middle
        last = current
    else:
        left = middle

print(toFixed(last, 2), file=fout)
fout.close()

