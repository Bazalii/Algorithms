fin = open("search1.in")
fout = open("search1.out", "w")
number = 0
answer = []
wanted_string = fin.readline().rstrip()
main_string = fin.readline().rstrip()
counter = len(wanted_string)
for i in range(len(main_string) - counter + 1):
    if wanted_string == main_string[i:i + counter]:
        answer.append(i + 1)
        number += 1
print(number, file=fout)
print(" ".join(map(str, answer)), file=fout)
