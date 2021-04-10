from sys import setrecursionlimit
import threading

graph = {}
Color = {}
Array = []
checker = 0
fin = open("cycle.in")
fout = open("cycle.out", "w")

setrecursionlimit(10 ** 9)
threading.stack_size(254217728)
def main():
    def dfs(v):
        global checker
        if Color.get(v) == 1:
            Color.update({v: 3})
            return True
        if Color.get(v) == 2:
            return False
        Color.update({v: 1})
        for i in graph.get(v):
            if dfs(i):
                if Color.get(i) == 3 and checker == 0:
                    checker += 1
                elif Color.get(i) == 3 and checker == 1:
                    print("YES", file=fout)
                    print(' '.join(map(str, Array)), file=fout)
                    exit(0)
                Array.insert(0, i)
                return True
        Color.update({v: 2})
        return False

    def topological_sort():
        for i in graph.keys():
            Cycle = dfs(i)
            if Cycle:
                print("YES", file=fout)
                print(' '.join(map(str, Array)), file=fout)
                exit(0)

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
    topological_sort()
    print("NO", file=fout)
thread = threading.Thread(target=main)
thread.start()
