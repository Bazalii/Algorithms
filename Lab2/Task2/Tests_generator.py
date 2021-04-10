import os
from random import randint

TESTS_DIR_NAME = "Generic_tests"
ANSWERS_DIR_NAME = "Generic_answers"

def clear_dir(dir_path: str) -> None:
    for file_path in os.listdir(dir_path):
        os.remove(f"{dir_path}/{file_path}")


def get_answer(file_path) -> int:
    with open(file_path, "r") as file:
        n = int(file.readline())
        values = list(map(int, file.readline().split()))
        answer = 0
        for i in range(len(values[:len(values) - 1])):
            for val in values[i + 1:]:
                if values[i] > val:
                    answer += 1
        return answer


if __name__ == "__main__":


    tests_amount = int(input("Print amount of tests: "))
    values_amount = int(input("Print max count of values: "))

    if TESTS_DIR_NAME not in os.listdir():
        os.mkdir(TESTS_DIR_NAME)
    if ANSWERS_DIR_NAME not in os.listdir():
        os.mkdir(ANSWERS_DIR_NAME)

    try:
        last = int(os.listdir(TESTS_DIR_NAME)[-1].replace("Generic_test#", '')) + 1
        last_answer = int(os.listdir(ANSWERS_DIR_NAME)[-1].replace("Generic_test#", '')) + 1
        if last != last_answer:
            clear_dir(TESTS_DIR_NAME)
            clear_dir(ANSWERS_DIR_NAME)
    except:
        last = 0
        last_answer = 0

    for i in range(tests_amount):
        val = randint(1, values_amount)
        with open(f'{TESTS_DIR_NAME}/Generic_test#{last}', "w") as file:
            print(val, file=file)
            for k in range(val - 1):
                print(randint(0, values_amount), file=file, end=' ')
            print(randint(0, values_amount), file=file, end='')

        with open(f'{ANSWERS_DIR_NAME}/Generic_answer#{last}', "w") as file:
            print(get_answer(f'{TESTS_DIR_NAME}/Generic_test#{last}'), file=file)

        last += 1
