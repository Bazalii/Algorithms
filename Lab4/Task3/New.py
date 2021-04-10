fin = open("brackets.in")
fout = open("brackets.out", "w")
Stack = []
Main_Array = []
checker_left = 0
for line in fin:
    Input_Array = line.rstrip()
    for i in range(len(Input_Array)):
        if Input_Array[i] == "(" or Input_Array[i] == "[" or Input_Array[i] == ")" or Input_Array[i] == "]":
            Main_Array.append(Input_Array[i])
    if len(Main_Array) % 2 == 0:
        for symbol in Main_Array:
            if symbol == "(" or symbol == "[":
                checker_left = 1
                Stack.append(symbol)
            elif symbol == ")":
                Stack.append(symbol)
                if len(Stack) != 0 and Stack[len(Stack) - 2] == "(":
                    Stack.pop()
                    Stack.pop()
            elif symbol == "]":
                Stack.append(symbol)
                if len(Stack) != 0 and Stack[len(Stack) - 2] == "[":
                    Stack.pop()
                    Stack.pop()
        if len(Stack) == 0 and checker_left == 1:
            fout.write("YES")
            fout.write('\n')
        else:
            fout.write("NO")
            fout.write('\n')
    else:
        fout.write("NO")
        fout.write('\n')
    Stack = []
    Main_Array = []
fout.close()
