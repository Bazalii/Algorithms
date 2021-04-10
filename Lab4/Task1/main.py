# fin = open("stack.in")
# fout = open("stack.out", "w")
# Stack = []
# number = fin.readline()
# for line in fin:
#     Input_Array = line.split()
#     if Input_Array[0] == "+":
#         Stack.append(Input_Array[1])
#     elif Input_Array[0] == "-":
#         print(Stack[len(Stack) - 1], file=fout)
#         Stack.pop(len(Stack) - 1)
# fout.close()

# class Stack:
#     def __init__(self):
#         self.items = []
#
#     def push(self, item):
#         self.items.insert(0, item)
#
#     def pop(self):
#         return self.items.pop(0)
#
#
# Main_Stack = Stack()
# fin = open("stack.in")
# fout = open("stack.out", "w")
# number = fin.readline()
# for line in fin:
#     Input_Array = line.split()
#     if Input_Array[0] == "+":
#         Main_Stack.push(Input_Array[1])
#     elif Input_Array[0] == "-":
#         print(Main_Stack.pop(), file=fout)
# fout.close()

Main_Stack = [0]*10000000
fin = open("stack.in")
fout = open("stack.out", "w")
number = fin.readline()
head = 0
for line in fin:
    Input_Array = line.split()
    if Input_Array[0] == "+":
        Main_Stack[head] = Input_Array[1]
        head += 1
    elif Input_Array[0] == "-":
        print(Main_Stack[head - 1], file=fout)
        head -= 1
fout.close()
