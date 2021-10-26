input="$BASH_SOURCE"
reverse=""
 
len=${#input}
for (( i=$len-4; i>=0; i-- ))
do 
	reverse="$reverse${input:$i:1}"
done

reverse+=".sh"

tac "$BASH_SOURCE"| rev > $reverse

