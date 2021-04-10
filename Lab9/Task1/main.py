from sys import setrecursionlimit
import threading

setrecursionlimit(10 ** 9)
threading.stack_size(67108864)
def main():
    def topological_sort(graph, Color):
        Stack = []
        def dfs(v):
            if Color.get(v) == 1:
                return True
            if Color.get(v) == 2:
                return False
            Color.update({v: 1})
            for i in graph.get(v):
                if dfs(i):
                    return True
            Stack.append(v)
            Color.update({v: 2})
            return False
        for i in graph.keys():
            Cycle = dfs(i)
            if Cycle:
                print(-1, file=fout)
                exit(0)
        Stack.reverse()
        fout.write(' '.join(map(str, Stack)))

    fin = open("topsort.in")
    fout = open("topsort.out", "w")
    Color = {}
    graph = {}
    Input_data = fin.readline().split()
    n, m = int(Input_data[0]), int(Input_data[1])
    if n == 1:
        print(1, file=fout)
        exit(0)
    for i in range(m):
        Input_data = fin.readline().split()
        k, r = int(Input_data[0]), int(Input_data[1])
        if graph.get(k) is not None and r not in graph.get(k):
            graph.update({k: graph.get(k) + [r]})
        elif graph.get(k) is None:
            graph.update({k: [r]})
    if len(graph.keys()) < n:
        for i in range(1, n + 1):
            if i not in graph.keys():
                graph.update({i: []})
    for i in graph.keys():
        Color[i] = 0
    topological_sort(graph, Color)

thread = threading.Thread(target=main)
thread.start()