fin = open("input.txt")
fout = open("output.txt", "w")
Input_data = fin.readline().split()
n, m = int(Input_data[0]), int(Input_data[1])
Array = [0] * n
for i in range(n):
    Array[i] = [0] * n
for line in fin:
    Input_data = line.split()
    n, m = int(Input_data[0]), int(Input_data[1])
    Array[n - 1][m - 1] = 1
print(Array)
for i in range(n):
    for j in range(n):
        fout.write(str(Array[i][j]))
        fout.write(" ")
    fout.write('\n')
