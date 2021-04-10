def Sum(Stack):
    Stack[len(Stack) - 2] += Stack[len(Stack)-1]

def Multiplication(Stack):
    Stack[len(Stack) - 2] *= Stack[len(Stack)-1]

def Subtraction(Stack):
    Stack[len(Stack) - 2] -= Stack[len(Stack)-1]

fin = open("postfix.in")
fout = open("postfix.out", "w")
Stack = []
Input_Array = fin.readline().rstrip().split()
for i in range(len(Input_Array)):
    if Input_Array[i].isdigit():
        Input_Array[i] = int(Input_Array[i])
for symbol in Input_Array:
    if symbol == "+":
        Sum(Stack)
        Stack.pop()
    elif symbol == "-":
        Subtraction(Stack)
        Stack.pop()
    elif symbol == "*":
        Multiplication(Stack)
        Stack.pop()
    else:
        Stack.append(symbol)
print(Stack[len(Stack)-1], file=fout)

fout.close()