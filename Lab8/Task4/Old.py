def dfs(graph, vertex, number):
    Component_numbers.setdefault(vertex, number)
    for i in graph.get(vertex):
        if i not in Component_numbers.keys():
            dfs(graph, i, number)


fin = open("components.in")
fout = open("components.out", "w")
Component_numbers = {}
Main_set = []
graph = {}
Input_data = fin.readline().split()
n, m = int(Input_data[0]), int(Input_data[1])
Graph = [0] * n
for i in range(n):
    Graph[i] = [0] * n
for i in range(m):
    Input_data = fin.readline().split()
    k, r = int(Input_data[0]), int(Input_data[1])
    Graph[k - 1][r - 1] = 1
    Graph[r - 1][k - 1] = 1
for i in range(n):
    for j in range(n):
        if Graph[i][j] == 1:
            Main_set.append(j)
    graph.setdefault(i, Main_set)
    Main_set = []
print(graph)
number = 1
Graph = []
for i in range(n):
    if i not in Component_numbers.keys():
        dfs(graph, i, number)
        number += 1
print(max(Component_numbers.values()), file=fout)
for i in range(n):
    fout.write(str(Component_numbers.get(i)))
    fout.write(" ")