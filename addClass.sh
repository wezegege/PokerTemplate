#!/bin/bash

function upper () {
	echo $1 | tr '[:lower:]' '[:upper:]'
}

function capitalize () {
	echo $1 | sed 's/\(.\)\(.*\)/\l\1\2/g'
}

function today () {
	date "+%d\\/%m\\/%Y"
}

module=$1
class=$2
inline=`[ $# -gt 2 ]`

templateDir=config/templates/
srcDir=src/
headerFile=defaultH.txt
sourceFile=defaultCPP.txt
inlineFile=defaultTPP.txt

cat ${templateDir}/${headerFile} | sed -e "s/%%CLASS%%/`capitalize ${class}`/g" -e "s/%%CLASS-u%%/`upper ${class}`/g" -e "s/%%CLASS-l%%/${class}/g" -e "s/%%DATE%%/`today`/g" > ${srcDir}/${module}/${class}.h
cat ${templateDir}/${sourceFile} | sed -e "s/%%CLASS%%/`capitalize ${class}`/g" -e "s/%%CLASS-u%%/`upper ${class}`/g" -e "s/%%CLASS-l%%/${class}/g" -e "s/%%DATE%%/`today`/g" > ${srcDir}/${module}/${class}.cpp
test ${inline} && cat ${templateDir}/${inlineFile} | sed -e "s/%%CLASS%%/`capitalize ${class}`/g" -e "s/%%CLASS-u%%/`upper ${class}`/g" -e "s/%%CLASS-l%%/${class}/g" -e "s/%%DATE%%/`today`/g" > ${srcDir}/${module}/${class}.tpp

