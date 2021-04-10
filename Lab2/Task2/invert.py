def get_answer(file_path) -> int:
    with open(file_path, "r") as file:
        n = int(file.readline())
        values = list(map(int, file.readline().split()))
        answer = 0
        for i in range(len(values[:len(values) - 1])):
            for val in values[i+1:]:
                if values[i] > val:
                    answer += 1
    return answer


fout = open("inversions.out", "w")
print(get_answer("inversions.in"), file=fout)