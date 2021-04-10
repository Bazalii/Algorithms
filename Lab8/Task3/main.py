fin = open("input.txt")
fout = open("output.txt", "w")
Input_data = fin.readline().split()
n, m = int(Input_data[0]), int(Input_data[1])
if m == 1 or n == 1:
    fout.write("NO")
    exit(0)
Array = [0] * n
for i in range(n):
    Array[i] = [0] * n
for i in range(m):
    Input_data = fin.readline().split()
    k, r = int(Input_data[0]), int(Input_data[1])
    Array[k - 1][r - 1] += 1
    Array[r - 1][k - 1] += 1
for i in range(n):
    for j in range(n):
        if i != j and (Array[i][j] > 1 or Array[j][i] > 1):
            fout.write("YES")
            exit(0)
fout.write("NO")
