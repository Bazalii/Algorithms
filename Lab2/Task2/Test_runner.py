import os
from Tests_generator import TESTS_DIR_NAME, ANSWERS_DIR_NAME

if __name__ == "__main__":
    sys_path_to_binary = input("Print path to binary: ")

    if len(os.listdir(TESTS_DIR_NAME)) != len(os.listdir(ANSWERS_DIR_NAME)):
        print("Wrong amount of answers or test")
        exit(0)

    with open("Log_file.txt", "w") as log:
        for i in range(len(os.listdir(TESTS_DIR_NAME))):
            with open("inversions.in", "w") as input_file:
                with open(f'{TESTS_DIR_NAME}/Generic_test#{i}', "r") as test:
                    input_file.writelines(test.readlines())

            os.system(sys_path_to_binary)

            with open("inversions.out", "r") as answer_file:
                with open(f'{ANSWERS_DIR_NAME}/Generic_answer#{i}', "r") as correct_answer_file:
                    correct_answer = int(correct_answer_file.readline())
                    program_answer = int(answer_file.readline())
                    if correct_answer == program_answer:
                        print(f"Generic_test#{i}: CORRECT", file=log)
                        print(f"Generic_test#{i}: CORRECT")
                    else:
                        print(f"Generic_test#{i}: INCORRECT!!! expected: {correct_answer} got: {program_answer}",
                              file=log)
                        print(f"Generic_test#{i}: INCORRECT!!! expected: {correct_answer} got: {program_answer}")
                        if input("Has incorrect answer, do you want to continue? (yes/no) ").strip().lower() != "yes":
                            exit(0)
