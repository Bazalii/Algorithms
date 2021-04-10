def merge(Array, left, mid, right):
    it1 = 0
    it2 = 0
    result = [0] * (right - left)
    while (left + it1 < mid) and (mid + it2 < right):
        if Array[left + it1] < Array[mid + it2]:
            result[it1 + it2] = Array[left + it1]
            it1 += 1
        else:
            result[it1 + it2] = Array[mid + it2]
            it2 += 1
    while left + it1 < mid:
        result[it1 + it2] = Array[left + it1]
        it1 += 1
    while mid + it2 < right:
        result[it1 + it2] = Array[mid + it2]
        it2 += 1
    for i in range(it1 + it2):
        Array[left + i] = result[i]


def Recursive_part_of_merge(a, left, right):
    if left + 1 >= right:
        return
    mid = int((left + right) / 2)
    Recursive_part_of_merge(a, left, mid)
    Recursive_part_of_merge(a, mid, right)
    merge(a, left, mid, right)


results_dict = {}
with open("race.in", "r") as input_file:
    n = int(input_file.readline())
    for i in range(n):
        country_name, runner_second_name = input_file.readline().split()
        if results_dict.get(country_name, False):
            results_dict[country_name].append(runner_second_name)
        else:
            results_dict[country_name] = [runner_second_name]
    sorted_list = list(results_dict.keys())
    Recursive_part_of_merge(sorted_list, 0, len(sorted_list))

with open("race.out", "w") as output_file:
    for key in sorted_list:
        print(f"=== {key} ===", file=output_file)
        for value in results_dict[key]:
            print(value, file=output_file)
