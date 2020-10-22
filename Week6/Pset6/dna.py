import sys
import csv

def read_database():
    with open(f"{filename_database}", "r") as file:
        reader = csv.reader(file)
        header = next(reader)
        strs.append(header[1:])
        for row in reader:
            str_data = {}
            for i in range(len(header)):
                str_data[header[i]] = row[i]
            str_datas.append(str_data)

def read_sequence():
    with open(f"{filename_sequence}", "r") as file:
        sequence = file.read()
    return sequence

def find_seq():
    for i in range(len(strs[0])):
        temp_seq = sequence
        counter = 0
        while (strs[0][i] in temp_seq):
            index = temp_seq.index(strs[0][i])
            index = index + len(strs[0][i])
            counter += 1
            temp_seq = temp_seq[index:]
        sequence_dict[strs[0][i]] = counter

def check_seq():
    for person in str_datas:
        check_sum = 0
        for strval in strs[0]:
            if int(person[strval]) == sequence_dict[strval]:
                check_sum += 1
        if check_sum == len(strs[0]):
            print(person["name"])
            return
    print("No match")

if len(sys.argv) != 3:
    print("missing command-line argument\n ")
    sys.exit(1)

str_datas=[]
strs = []
sequence_dict = {}

filename_database = sys.argv[1]
filename_sequence= sys.argv[2]
read_database()
sequence = read_sequence()
find_seq()
check_seq()

#print(strs)
#print(sequence)
#print(str_datas)
#print(sequence_dict)

sys.exit(0)
