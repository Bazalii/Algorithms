fin = open("queue.in")
fout = open("queue.out", "w")
Queue = [0]*1000000
head = 0
tail = 0
checker = 0
number = fin.readline()
for line in fin:
    checker += 1
    Input_Array = line.split()
    if Input_Array[0] == "+":
        Queue[tail] = Input_Array[1]
        tail += 1
    elif Input_Array[0] == "-":
        print(Queue[head], file=fout)
        head += 1
fout.close()
