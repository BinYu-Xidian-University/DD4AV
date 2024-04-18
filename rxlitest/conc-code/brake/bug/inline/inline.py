#!/usr/bin/python

import sys

# get arguments from command line
arg_list = []
for arg in sys.argv:
	arg_list.append(arg)

# constants
#prefix = "__VERIFIER"
prefix = "__CPROVER"
func_name = arg_list[3]
atomic_begin_stmt = prefix + "_atomic_begin();\n"
atomic_end_stmt = prefix + "_atomic_end();\n"
assume_stmt = "TRANS_atomic_assume_" + func_name + "();\n"
atomic_assume_stmt = "__VERIFIER_atomic_TRANS_atomic_assume_" + func_name + "();\n"

# start translation
line_no = 0;
input_file = open(arg_list[1], "rU")
output_file = open(arg_list[2], "w")
lines = input_file.readlines()

for line in lines:
	line_no += 1
	line2 = line.strip('\t').strip().rstrip('\n')
	# blank line and comments
	if line2 == "" or \
           line2.startswith("//") or \
           line2.startswith("/*") or \
           line2.startswith("*") or \
           line2.startswith("*/"):
		output_file.write(line)
	elif "if" in line or "else" in line or line2 == "}":
		output_file.write(atomic_assume_stmt)
		output_file.write(line)
	else:
		output_file.write(atomic_assume_stmt)
		output_file.write(atomic_begin_stmt)
		output_file.write(assume_stmt)
		output_file.write(line)
		output_file.write(assume_stmt)
		output_file.write(atomic_end_stmt)
		output_file.write('\n')

input_file.close()
output_file.close()
