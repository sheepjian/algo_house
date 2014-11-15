if [[ $1 = "delete" ]]; then
	#statements
	rm -rf $2
fi

if [[ $1 = "create" ]]; then
	#statements
	if [[ ! -d "$2" ]]; then
		#statements
		mkdir $2
		dt=$(date '+%Y-%m-%d %H:%M:%S');
		sed -e "s/\[FILE_NAME\]/$2/g" -e "s/\[CREATE_TIME\]/$dt/g" Common/template.txt > $2/$2.cpp
	else
		echo "the question already exist"
	fi
fi