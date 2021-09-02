def make_hash():
    for i in range(wanted_string_size):
        hashes[0] += ord(main_string[i]) * hash_const ** (wanted_string_size - i - 1)
    hashes[0] = hashes[0] % division_const
    for i in range(main_string_size - wanted_string_size):
        print(hashes[i] * hash_const - ord(main_string[i]) * hash_const ** wanted_string_size + ord(main_string[i + wanted_string_size]))
        hashes[i + 1] = (hashes[i] * hash_const - ord(main_string[i]) * hash_const ** wanted_string_size + ord(main_string[i + wanted_string_size])) % division_const

fin = open("search2.in")
fout = open("search2.out", "w")
number = 0
hash_const = 7
division_const = 131
answer = []
wanted_string = fin.readline().rstrip()
main_string = fin.readline().rstrip()
main_string_size = len(main_string)
wanted_string_size = len(wanted_string)
if main_string_size < wanted_string_size:
    print(0, file=fout)
    exit(0)
hashes = [0] * (main_string_size - wanted_string_size + 1)
make_hash()
print(hashes)
wanted_hash = 0
for i in range(wanted_string_size):
    wanted_hash += ord(wanted_string[i]) * hash_const ** (wanted_string_size - i)
wanted_hash = hashes[0] % division_const
for i in range(main_string_size - wanted_string_size + 1):
    if hashes[i] != wanted_hash:
        continue
    checker = True
    for j in range(wanted_string_size):
        if main_string[i + j] != wanted_string[j]:
            checker = False
            break
    if checker:
        answer.append(i + 1)
        number += 1
print(number, file=fout)
print(" ".join(map(str, answer)), file=fout)
