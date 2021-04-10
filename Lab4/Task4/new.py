def Sum(Stack):
    Stack[head - 2] += Stack[head - 1]

def Multiplication(Stack):
    Stack[head - 2] *= Stack[head - 1]

def Subtraction(Stack):
    Stack[head - 2] -= Stack[head - 1]

fin = open("postfix.in")
fout = open("postfix.out", "w")
head = 0
Stack = [0]*1000
Input_Array = fin.readline().rstrip().split()
for i in range(len(Input_Array)):
    if Input_Array[i].isdigit():
        Input_Array[i] = int(Input_Array[i])
for symbol in Input_Array:
    if symbol == "+":
        Sum(Stack)
        head -= 1
    elif symbol == "-":
        Subtraction(Stack)
        head -= 1
    elif symbol == "*":
        Multiplication(Stack)
        head -= 1
    else:
        Stack[head] = symbol
        head += 1
print(Stack[head - 1], file=fout)
fout.close()