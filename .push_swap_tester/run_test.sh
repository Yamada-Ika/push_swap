#!/bin/bash

ARG="25682 13601 6747"
for i in {0..100}
do
	../push_swap 25682 13601 6747 | ../checker 25682 13601 6747
	../push_swap $ARG | ../checker $ARG
	# ../push_swap 25682 13601 6747 | ./checker_Mac 25682 13601 6747
	# ../push_swap $ARG | ./checker_Mac $ARG
done
exit 0

function CLEAN_TEST_DIR() {
	rm -rf *.out *.diff
}

function TAKE_LOG_FAILE_TEST() {
	test_case="$1"
	result_file="$2"
	expected_file="$3"
	echo "KO case : $test_case"
	# echo $result_file $expected_file
	echo "===============================================================" >> faile.log
	echo "test case : $test_case" >> faile.log
	echo "------------------------- diff result -------------------------" >> faile.log
	diff -a -u $result_file $expected_file >> faile.log
	echo "--------------------------- result ----------------------------" >> faile.log
	cat $result_file >> faile.log
	echo "--------------------------- expect ----------------------------" >> faile.log
	cat $expected_file >> faile.log
	echo "===============================================================" >> faile.log
}

function IS_SAME_FILE() {
	file_1="$1"
	file_2="$2"
	diff $file_1 $file_2 > out.diff
	size=$(ls -l out.diff | awk '{print $5}')
	if [ $size -eq 0 ]
	then
		return 0
	else
		return 1
	fi
}

function TEST() {
	ARG=$1
	CLEAN_TEST_DIR
	../push_swap $ARG 2> /dev/null | ../checker $ARG > result.out 2>&1
	../push_swap $ARG 2> /dev/null | ./checker_Mac $ARG > expected.out 2>&1
	IS_SAME_FILE result.out expected.out
	if [ $? -eq 0 ]
	then
		echo -e "\n\033[32mOK!\033[m"
	else
		echo -e "\n\033[31mKO!\033[m"
		TAKE_LOG_FAILE_TEST "$ARG" result.out expected.out
		# export TEST_STATUS=1
		exit 0
	fi
}

function NORMAL_TEST() {
	min_val="$1"
	max_val="$2"
	ARG=$(for i in `seq $min_val $max_val`; do echo -n "$RANDOM "; done;)
	TEST "$ARG"
}

rm -rf *.log

for i in `seq 1 100`
do
	NORMAL_TEST 1 3
done

for i in `seq 1 100`
do
	NORMAL_TEST 1 5
done

# for i in `seq 1 100`
# do
# 	NORMAL_TEST 1 20
# done

# for i in `seq 1 100`
# do
# 	NORMAL_TEST 1 100
# done
