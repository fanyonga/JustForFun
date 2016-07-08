a=1
b=1
((count=$1-2))
echo $a $b $count
while [[$count -gt 0 ]]
do
	((b=$a+$b))
	((a=$b-$a))
	if [[ $(($count%2)) -eq 0]]
	then echo $a
	else echo $b
	fi
	((count--))
done
