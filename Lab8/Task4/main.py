from sys import setrecursionlimit
import threading

setrecursionlimit(10 ** 9)
threading.stack_size(67108864)
def main():
    def dfs(graph, vertex, number):
        Component_numbers.update({vertex: number})
        for i in graph.get(vertex):
            if i not in Component_numbers.keys():
                dfs(graph, i, number)

    fin = open("components.in")
    fout = open("components.out", "w")
    Component_numbers = {}
    graph = {}
    Input_data = fin.readline().split()
    n, m = int(Input_data[0]), int(Input_data[1])
    if n == 1:
        print(1, file=fout)
        print(1, file=fout)
        exit(0)
    for i in range(m):
        Input_data = fin.readline().split()
        k, r = int(Input_data[0]), int(Input_data[1])
        if graph.get(k) is not None and r not in graph.get(k):
            graph.update({k: graph.get(k) + [r]})
        elif graph.get(k) is None:
            graph.update({k: [r]})
        if graph.get(r) is not None and k not in graph.get(r):
            graph.update({r: graph.get(r) + [k]})
        elif graph.get(r) is None:
            graph.update({r: [k]})
    if len(graph.keys()) < n:
        for i in range(1, n + 1):
            if i not in graph.keys():
                graph.update({i: []})
    number = 1
    for i in range(1, n + 1):
        if i not in Component_numbers.keys():
            dfs(graph, i, number)
            number += 1
    print(max(Component_numbers.values()), file=fout)
    for i in range(1, n + 1):
        fout.write(str(Component_numbers.get(i)))
        fout.write(" ")


thread = threading.Thread(target=main)
thread.start()


