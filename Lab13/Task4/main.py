import string
n = int(input())
main_string = input()
alphabet = string.ascii_lowercase
alphabet = alphabet[0:n]
number_of_states = len(main_string) + 1
states = [0] * number_of_states
for i in range(number_of_states):
    states[i] = [0] * n
prefix = [0] * (number_of_states)
i = 1
j = 0
while i < number_of_states - 1:
    if main_string[i] == main_string[j]:
        prefix[i + 1] = j + 1
        i += 1
        j += 1
    else:
        if j > 0:
            j = prefix[j]
        else:
            prefix[i + 1] = 0
            i += 1
print(prefix)
for i in range(number_of_states - 1):
    for j in range(n):
        if alphabet[j] == main_string[i]:
            states[i][j] = i + 1
        else:
            states[i][j] = states[prefix[i]][j]
    print(" ".join(map(str, states[i])))
for i in range(n):
    states[number_of_states - 1][i] = states[prefix[number_of_states - 1]][i]
print(" ".join(map(str, states[number_of_states - 1])))