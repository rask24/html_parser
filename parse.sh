#!/bin/zsh

opt=$1
outputfile="./output/dom.json"

usage ()
{
	cat << EOM
Usage: parse.sh OPTION
OPTION
	biuld	build html parser, create a.out
	run		execute a.out, output ./output/dom.json
	test	print ./output/dom.json recursively
EOM
}

if [ -z $opt ]; then
	usage
	exit 1
fi

if [ $opt = run ]; then
	make -s
	./a.out
elif [ $opt = build ]; then
	make
elif [ $opt = test ]; then
	if [ -f $outputfile ]; then
		node ./js/test.js
	else
		echo "error: ./output/dom.json does not exist"
		echo "please execute ./parse run before test"
		exit 2
	fi
else
	echo "error: invalid argument"
fi

