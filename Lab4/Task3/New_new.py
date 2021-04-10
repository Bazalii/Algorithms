fin = open("brackets.in")
fout = open("brackets.out", "w")
Stack = [0]*10000
head_stack = 0
head_array = 0
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
                Stack[head_stack] = symbol
                head_stack += 1
            elif symbol == ")":
                Stack[head_stack] = symbol
                head_stack += 1
                if head_stack != 0 and Stack[head_stack - 2] == "(":
                    head_stack -= 1
                    head_stack -= 1
            elif symbol == "]":
                Stack[head_stack] = symbol
                head_stack += 1
                if head_stack != 0 and Stack[head_stack - 2] == "[":
                    head_stack -= 1
                    head_stack -= 1
        if head_stack == 0 and checker_left == 1:
            fout.write("YES")
            fout.write('\n')
        else:
            fout.write("NO")
            fout.write('\n')
    else:
        fout.write("NO")
        fout.write('\n')
    Stack = [0]*10000
    Main_Array = []
    head_stack = 0
fout.close()
