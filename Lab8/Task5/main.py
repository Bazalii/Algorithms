from queue import Queue
def BFS(graph, source, n):
    Visited = []
    Main_queue = Queue()
    d = [0] * n
    Main_queue.put(source)
    while not Main_queue.empty():
        u = Main_queue.get()
        Visited.append(u)
        for j in graph.get(u):
            if d[j] == 0:
                d[j] = d[u] + 1
                Main_queue.put(j)
    d[0] = 0
    return d


fin = open("pathbge1.in")
fout = open("pathbge1.out", "w")
Input_data = fin.readline().split()
n, m = int(Input_data[0]), int(Input_data[1])
graph = {}
for i in range(m):
    Input_data = fin.readline().split()
    k, r = int(Input_data[0]) - 1, int(Input_data[1]) - 1
    if graph.get(k) is not None and r not in graph.get(k):
        graph.update({k: graph.get(k) + [r]})
    elif graph.get(k) is None:
        graph.update({k: [r]})
    if graph.get(r) is not None and k not in graph.get(r):
        graph.update({r: graph.get(r) + [k]})
    elif graph.get(r) is None:
        graph.update({r: [k]})
fout.write(str(' '.join(map(str, BFS(graph, 0, n)))))