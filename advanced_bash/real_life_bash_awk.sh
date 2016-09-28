#!/bin/bash

# remove the folder if already present. redirect output to /dev/null
rm -rf post_processing_$1/ >& /dev/null
# make directory named "post_processing_name_of_the_file"
mkdir post_processing_$1
input=`echo $PWD`/$1
cd post_processing_$1

#============================================= 
#        cycle's number
#============================================= 

echo -n "reading cycle's numbers..."

awk '/ENTERING CYCLE/ {printf $5 "	"}' $input > cycles.csv

echo "done"

#============================================= 
#         mass balances
#============================================= 

mkdir masses
cd masses
echo -n "reading masses... this may take a while, please be patient..."

awk '/mass balance at BOC/ , /END OF MODULE MATERIAL_BALANCE_EDITION/' $input > mass_boc.temp

awk '/mass balance at EOC/ , /END OF MODULE MATERIAL_BALANCE_EDITION/' $input > mass_eoc.temp

awk '/mass balance after cooling/ , /END OF MODULE MATERIAL_BALANCE_EDITION/' $input > mass_cool.temp

# awk '/difference between BOC and EOC/ , /END OF MODULE MATERIAL_BALANCE_EDITION/' $input > mass_diff.temp

# we are going to do some nested loops

declare -a files
files=(mass_boc.temp mass_eoc.temp mass_cool.temp)

declare -a labels
labels=(boc eoc cool)

declare -a fuels
fuels=(IF1 IF2 IF3 OF1 OF2 OF3 BLKI1 BLKI2 BLKI3 BLKO1 BLKO2 BLKO3)

declare -a list
list=(Th232 Pa231 Pa233 U232  U233  U234  U235  U236  U237  U238  Np237 Np238 Np239 Pu238 Pu239 Pu240 Pu241 Pu242 Am241 Am242m Am243 Cm242 Cm243 Cm244 Cm245 Cm246 Cm247 Cm248 Ra226 Th229 Th230 Th233 Th234 Pa232 Np236 Pu236 Pu237 Pu243 Pu244 Am242g 'Am244 ' Am244m Cm241 Bk249 Cf249 Cf250 Cf251 Cf252)

declare -i j
j=0

for file in "${files[@]}" # BOC , EOC , cooling
do
    for fuel in "${fuels[@]}" # IF1 , IF2, ..., OF1, ..., BLKI1, ..., BLKO1, ...
    do
	awk -v var="$fuel" '$0 ~ var , /TOTAL/ {
	    if ( $2 !~ "sfp" ) {
		print $0 }
	    }' $file > `echo $fuel`_$file
	name=`echo $fuel`_`echo ${labels[j]}`.csv # IF1_boc.csv, ..., IF2_boc.csv, ..., BLKO3_cool.csv
	touch $name
	for iso in "${list[@]}"
	do
	    echo -n $iso "	" >> $name
	    awk -v is="$iso" '$0 ~ is { printf $4 "	"}' `echo $fuel`_$file >> $name
	    echo "" >> $name
	done
    done
    j=$j+1
done

rm *.temp
echo "done"
cd ..

#============================================= 
#        feeds
#============================================= 

mkdir feeds
cd feeds
echo -n "reading feeds..."


declare -a kind
kind=(TRU Th)

declare -a where
where=(IF OF)

declare -a number
number=(1 2 3)


for k in "${kind[@]}"
do
    for w in "${where[@]}"
    do
	for n in "${number[@]}"
	do
	    regexp="$k added to $w$n"
	    awk -v var="$regexp" '$0 ~ var {print $8 }' $input > `echo $w$n`_`echo $k`.csv
	done
    done
done
echo "done"
cd ..

#============================================= 
#       keff
#============================================= 

echo -n "reading keff..."

awk '/RESULT / , / 365 / { if ($1~"DAYS") {getline ; printf $2 "       "}}' $input > keff.csv 
echo "" >> keff.csv
awk '/RESULT / , / 365 / { if ($1~"DAYS") {getline ;  getline ; printf $2 "       "}}' $input >> keff.csv 
echo "" >> keff.csv
awk '/RESULT / , / 365 / { if ($1~"DAYS") {getline ;  getline ;  getline ; printf $2 "       "}}' $input >> keff.csv 
echo "" >> keff.csv
awk '/RESULT / , / 365 / { if ($1~"DAYS") {getline ;  getline ;  getline ;  getline ; printf $2 "       "}}' $input >> keff.csv 

echo "done"
