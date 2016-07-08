if [ $# -le 1 ]
	then
	echo "input error.filename is needed"
	exit
else
	echo -n "Please type in a directory name:"
	read fname
	if [ -d $fname]
		then
		for name
		do
			if [ -f $name]
				then
				cp $name $fname
				echo  "$name is copyed!"
			else
				echo "$name is not a file"
			fi
		done
	else
		echo "$fname is not a directory"
	fi
fi