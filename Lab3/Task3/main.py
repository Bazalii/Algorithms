def Count_Sort(Array, size, col, base, m):
    output = [0] * size
    count = [0] * (base + 1)
    min_base = ord('a') - 1
    for item in Array:
        letter = ord(item[col]) - min_base if col < len(item) else 0
        count[letter] += 1
    for i in range(len(count) - 1):
        count[i + 1] += count[i]
    for item in reversed(Array):
        letter = ord(item[col]) - min_base if col < len(item) else 0
        output[count[letter] - 1] = item
        count[letter] -= 1
    return output

def Radix_Sort(Array, k, m):
    counter = 0
    for col in range(m - 1, -1, -1):
        Array = Count_Sort(Array, len(Array), col, 26, m)
        if counter == k-1:
            break
        else:
            Array = Count_Sort(Array, len(Array), col, 26, m)
        counter += 1
    return Array

fin = open("radixsort.in")
fout = open("radixsort.out", "w")
Input_Array = fin.readline().split()
n = int(Input_Array[0])
m = int(Input_Array[1])
k = int(Input_Array[2])
Array_Main = []
for i in range(n):
    Array_Main.append(str(fin.readline().rstrip()))
Array_Main = Radix_Sort(Array_Main, k, m)
for i in range(len(Array_Main)):
    print(Array_Main[i], file=fout)
fout.close()
