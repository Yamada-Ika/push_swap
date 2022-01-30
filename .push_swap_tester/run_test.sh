#!/bin/bash

function CLEAN_TEST_DIR() {
	rm -rf *.out *.diff
}

function TAKE_LOG_FAILE_TEST() {
	test_case="$1"
	result_file="$2"
	expected_file="$3"
	res_step="$4"
	exp_step="$5"
	echo "===============================================================" >> faile.log
	echo "test case : $test_case" >> faile.log
	echo "--------------------------- result ----------------------------" >> faile.log
	cat $result_file >> faile.log
	echo $res_step >> faile.log
	echo "--------------------------- expect ----------------------------" >> faile.log
	cat $expected_file >> faile.log
	echo $exp_step >> faile.log
	echo "===============================================================" >> faile.log
}

function IS_SAME_FILE() {
	file_1="$1"
	file_2="$2"
	diff $file_1 $file_2 > out.diff
	content_file_1=$(cat $file_1)
	content_file_2=$(cat $file_2)
	if [ $content_file_1 = "Error" ] && [ $content_file_2 = "Error" ]
	then
		export error_case=1
	fi
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
	../push_swap $ARG 2> /dev/null | ../checker $ARG > result.out 2>&1
	../push_swap $ARG 2> /dev/null | ./checker_Mac $ARG > expected.out 2>&1
	IS_SAME_FILE result.out expected.out
	echo "case : $ARG"
	if [ $? -eq 0 ]
	then
		echo -e "\n\033[32mOK!\033[m"
	else
		echo -e "\n\033[31mKO!\033[m"
		TAKE_LOG_FAILE_TEST "$ARG" result.out expected.out "" ""
	fi
}

function ORDER_STEP_TEST() {
	ARG=$1
	EXPECTED=$2
	RES=$(../push_swap $ARG | wc -l)
	echo $RES
	if [ $RES -le $EXPECTED ]
	then
		echo -e "\n\033[32mORDER_STEP_TEST : $EXPECTED GREAT!\033[m\n"
	else
		echo -e "\n\033[31mORDER_STEP_TEST : $EXPECTED so so...\033[m\n"
		TAKE_LOG_FAILE_TEST "$ARG" result.out expected.out "$RES" "$EXPECTED"
		exit 0
	fi
}

function NORMAL_TEST() {
	CLEAN_TEST_DIR
	min_val="$1"
	max_val="$2"
	ARG=$(for i in `seq $min_val $max_val`; do echo -n "$RANDOM "; done;)
	export error_case=0
	TEST "$ARG"
	if [ $error_case -eq 1 ]
	then
		return 0
	fi
	if [ $1 -eq 1 ] && [ $2 -eq 3 ]
	then
		ORDER_STEP_TEST "$ARG" 6
	fi
	if [ $1 -eq 1 ] && [ $2 -eq 5 ]
	then
		ORDER_STEP_TEST "$ARG" 12
	fi
	if [ $1 -eq 1 ] && [ $2 -eq 100 ]
	then
		ORDER_STEP_TEST "$ARG" 700
	fi
	if [ $1 -eq 1 ] && [ $2 -eq 500 ]
	then
		ORDER_STEP_TEST "$ARG" 5500
	fi
}

rm -rf *.log
CLEAN_TEST_DIR

# faile case
TEST "\"0 1\" 3 2"
TEST "0 '1 3' 2"
TEST "a 0 1 c 3 2"
TEST "-1 0 1a c 3 2"
TEST "-1 0 1a c 3 2"
TEST "-1 = -2"
TEST "-1 0 1a c 3 2"
TEST "2147483648 0 2 1"
TEST "2 2147483648 0"
TEST "-2147483649 0 2 1"
TEST "'<l0t#0 ye!*7r- >jcb*7: uhr&igd :b;\"m>6 v5pr\\% *\"(+<}q ga+xv4l 4%u|6h' ai6l#h<%"
TEST "8!fo0gn v%k'1[c ?^{0gso 5+e\$4.p 0*55ptr ry*g,|& 04:3,^6 <ei;d-; c*;=\e& 3[60pi]"
TEST "g\"l3%i qd;dx\"d v(%<{]n xa_p8y* j<ts^.v y{g'5{f :7l[q,: r>+xcy= fi?.\"n) d88}m*y"
TEST "18ab753 3423c2c b308b50 bcc4123 0ba71b0 46c8416 cc27022 660a611 1bba421 64a008b%"
TEST "35'2'10 87-18'6 0'2'283 231861- -2'-+64 0'7\"60- 427538' -+346'- \"1+'838 605'783%"
TEST "18P \"WF 08I3855 1+2'PFE 7226 45 22\"5'5\" 2I8-\"+' 00FP'\"5 14-0W+8 5\"63\"'W F11EPE3 80860 8 7 62010 F12FP\"+ 334+\"1' 50\"\"-I6 718WW-8 I-IW2WF  +\"F\"4I -4-37P+ W6 8+20% "
TEST "5131' 4 8384352 3750\"5  316\"785 2'0 614 46\"1228 4' 8357 1101\" 4 4167006 445 \"76 412'158  428588 24 '851 361\"576 6025\"63 6\"23104 0\"\"5746  011'\"7 47\"5  2  '\"7\"\"\"%"
TEST "0518726 701421' '030\"44 343\"077 5\"64583 8536888 7\"45632 103 1\"0 32855 6   0'351 0447813 8276665 6567012 426 3'1  85\"3'2 1 4366\" \"\"13488 4\"73064  22551' 1\"'\"201"
TEST "2700475  875721 56635 2 7'2\"702 3464\"40 1 1 ' 8 1536\"64 '16'608  \"  373 31216\"5 7220''  274 4\"0 132 '2  5  155' 74'5203 '251481  55\"272 41'1603 717 610 ''03'23"
TEST "33366'74337784602700\"88 12'36\" 513'8'4 515\"1\"\"'2518458241778  7023062667'84\"67 46481324' 038 0'752'0 31 512650138403 622785 45  0565568 3485526285473 4265 44'848 72 630\"28004 37860'1  6 20456'310\"10\"8660'''7455211\"3  5\"834882346685\"\"7 2 27'6332\"54 08\" 22\" 31 2531854\"3\"2450' 748 '25'63\"  15\"683'\"223 0510 '520 3 583561'3'400\"3'152678\"\"23731 363 7\"554\"2 356517'8348\"2072 2 33686383336012134\"714564606'85 75\"3155815834511 23 10053542 3 5 1 34 24015806'07768\"057 '\"84 381'362 '4\"71\"5\" 21277085\"36\"5 2\"'6\"562'3748'3\"\"'751158332730 74  311837'\"57\"3345\"45\"''24 63 '21'50 03342''56412761'' \"555' 4'352368'328\"64 12887063254\"0 "
TEST "34475051 00'681642 814007 821' 138'16' 671'8 3'52844465'07843 046255 88'73' 3'0 2623 '348075 6064786'238 37147 173 6'4701'8 6655511767 7664'28'11878'26735 63187'3780363 744587434057008  3301437522780384762582164 3527 404500332674830036'26'36650578 350 47867'712'6067 '2708738443 2''233387503 82 70132 87'21'54 44117'0 141363887568862'607644 4775  67'0442'0730 77242658'50 2806214631612518 3755437126431  87 867328'    4'156 7540233'5 6'807165722' 8414 881062703266 '32877 11536877''87127468 5344 621  1 88'383'886  5 7 87202'6 088361147' 8'16453426780 7 '5' 64   2'81056 10'468'231 3'5'83 02' 645'7'680'44 188325711' 32"

# INT_MAX, INT_MIN case
TEST "2147483647 0 2 1"
TEST "-2147483648 0 2 1"

for i in `seq 1 100`
do
	NORMAL_TEST 1 3
done

for i in `seq 1 100`
do
	NORMAL_TEST 1 5
done

for i in `seq 1 100`
do
	NORMAL_TEST 1 100
done

for i in `seq 1 100`
do
	NORMAL_TEST 1 500
done

unset error_case
CLEAN_TEST_DIR
