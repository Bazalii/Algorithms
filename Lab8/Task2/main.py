fin = open("input.txt")
fout = open("output.txt", "w")
Input_data = []
n = int(fin.readline())
Array = [0] * n
for i in range(n):
    Array[i] = [0] * n
for k in range(n):
    Input_data = fin.readline().split()
    for i in range(n):
        Array[k][i] = int(Input_data[i])
for i in range(n):
    for j in range(n):
        if (Array[i][j] != Array[j][i]) or (i == j and Array[i][j] == 1):
            fout.write("NO")
            exit(0)
fout.write("YES")

