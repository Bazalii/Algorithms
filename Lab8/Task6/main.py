from queue import Queue
def BFS(graph, source, n):
    Ways = {}
    Ways.update({start: []})
    Visited = []
    Main_queue = Queue()
    d = [0] * (n + 1)
    for i in range(0, n + 1):
        d[i] = [0] * 2
    Main_queue.put(source)
    while not Main_queue.empty():
        u = Main_queue.get()
        if u != start:
            Ways.update({u: Ways.get(d[u][1]) + [d[u][1]]})
        Visited.append(u)
        for j in graph.get(u):
            if d[j][0] == 0:
                d[j][1] = u
                d[j][0] = d[u][0] + 1
                Main_queue.put(j)
    return Ways.get(end)

fin = open("input.txt")
fout = open("output.txt", "w")
Vertexes = []
Main_set = []
graph = {}
Input_data = fin.readline().split()
n, m = int(Input_data[0]), int(Input_data[1])
line = 0
for i in range(n):
    Input_data = fin.readline()
    for j in range(m):
        if Input_data[j] == '.':
            Vertexes.append(j + line * m)
        elif Input_data[j] == 'S':
            Vertexes.append(j + line * m)
            start = j + line * m
        elif Input_data[j] == 'T':
            Vertexes.append(j + line * m)
            end = j + line * m
    line += 1
for i in Vertexes:
    if i + 1 in Vertexes and (i + 1) % m != 0:
        Main_set.append(i + 1)
    if i - 1 in Vertexes and i % m != 0:
        Main_set.append(i - 1)
    if i + m in Vertexes:
        Main_set.append(i + m)
    if i - m in Vertexes:
        Main_set.append(i - m)
    graph.update({i: Main_set})
    Main_set = []
way = BFS(graph, start, max(Vertexes))
if not isinstance(way, list):
    print(-1, file=fout)
    exit(0)
print(len(way), file=fout)
way.append(end)
for i in range(1, len(way)):
    if m == 1:
        if way[i - 1] == way[i] - m:
            fout.write("D")
        elif way[i - 1] == way[i] + m:
            fout.write("U")
    else:
        if way[i - 1] == way[i] - 1:
            fout.write("R")
        elif way[i - 1] == way[i] + 1:
            fout.write("L")
        elif way[i - 1] == way[i] - m:
            fout.write("D")
        elif way[i - 1] == way[i] + m:
            fout.write("U")



