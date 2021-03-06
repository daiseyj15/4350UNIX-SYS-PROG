#NAME:______Daisey_Jaramillo________																						
#CS4350– Unix Systems Programming
#Section	Number:	001	
#Assignment Number: ____2_______
#Due Date: 9/23/2020   no later than 5:15pm.
# !/bin/sh
functOne()
{
  echo "1) The numbers are  $num1  $num2  $num3"	
}

Function_Two()
{
	i=`expr $num1 + $num2 + $num3`
	return $i
}

Function_Three()
{
 	d=`expr $num1 \* $num2 \* $num3`
	return $d
}

Function_Four()
{
	s=`expr $two / 3`
	return $s
}

Function_Five()
{
echo 

	oneSq = `expr $num1 \* $num1`
	twoSq = `expr $num2 \* $num2`
	threeSq = `expr $num3 \* $num3`
echo "5) $num1 * $num1 = $oneSq , $num2 * $num2 = $twoSq , $num3 * $num3 = $threeSq"

}

Function_Six()
{
echo
echo "6) "
	if[$num1 -ge 0]
	then
	 echo "$num1 is positive, "
	else
	 echo "$num1 is negative, "
	fi
	if[$num2 -ge 0]
	then
	 echo "$num2 is positive, "
	else
	 echo "$num2 is negative, "
	fi
	if[$num3 -ge 0]
	then
	 echo "$num3 is positive."
	else
	 echo "$num3 is negative."
	fi
}

Function_Seven()
{
echo 
echo "7) "
	if[$(($num1 % 2)) -eq 0]
	then
	echo "$num1 is even, "
	else
	echo "$num1 is odd, "
	fi
	if[$(($num2 % 2)) -eq 0]
	then
	echo "$num2 is even, "
	else
	echo "$num2 is odd, "
	fi
	if[$(($num3 % 2)) -eq 0]
	then
	echo "$num3 is even"
	else
	echo "$num3 is odd"
	fi

}

Function_Eight()
{
#all the even and odd numbers between 1 and num2

echo "8) All odd numbers between 1 and $num2 are:"
echo
a = 2
while["$a" -lt "$num2"]
do
	if[$(($a % 2)) -eq 0]
	then
	continue
	else
	echo "$a "
	fi
a=`expr $a +1`
done

echo
echo "9) All even numbers between 1 and $num2 are:"
echo 
b=2
while["b" -lt "$num2"]
do
	if[$(($b % 2)) -eq 0]
	then
	echo "$b "
	else
	continue
	fi
b=`expr $b +1`
done
}

Function_Nine()
{
#must do with recursion, factorial of num1
	if["$1" -gt "1"];then
		i=`expr $1 - 1`
		j=`Function_Nine $i`
		k=`expr $1 \* $j`
		return $k
	else 
		return 1
	fi
}

Function_Ten()
{
#check if number3 is positive if not then return error message
#also sayif it is prime or not


	if[$num3 -lt 0]
	then
	echo
	echo "11) ERROR $num3 is a negative number"
	return
	fi

numOfFacs = `factor $num3 | wc -w`

if[$numOfFacs -gt 2] 
then
	ans = " is not prime"
else
	ans = " is prime"
fi

	return $ans
}


echo "The function of This script is to :"
echo
echo "1. Display the integer arguments that are entered."
echo "2. Sum of the 3 integer arguments."
echo "3. Product of the 3 integer arguments."
echo "4. Average of the 3 integer arguments."
echo "5. Square of each integer argument."
echo "6. Determine that each integer argument is positive, negative or" 
echo "   zero."
echo "7. Determine that each integer argument is odd, or even"
echo "8. Find the all odd and even numbers between 1 and the second" 
echo "   integer argument."
echo "9. Find the factorial of the first integer argument."
echo "10. Determine whether or not the third integer argument is a" 
echo "   prime number."
echo
echo




flag = 1

read -p 'Enter 3 integer Values ----> ' num1 num2 num3


while[$flag -eq 1];do 

  while[-z "$num3"];do 
	echo
	echo "**** Error - Must input 3 integer Values" 
	echo
	read -p 'Run the script again Y|N ----> ' yORn
	case "$yORn" in
	    Y | y)	echo
			read -p 'Enter 3 integer Values ----> ' num1 num2 num3
			echo
			;;

	    N | n)	flag = 0
			break
			;; 

	    *)	echo "**** Error - Must input Y or N"
		echo 
		while["$yORn" != "Y"]||["$yORn" != "y"]||["$yORn" != "n"]||["$yORn" != "N"];
		do
			read -p 'Run the script again Y|N ----> ' yORn
			if["$yORn" = "n"] || ["$yORn" = "N"]
			then
			flag=0
			fi
			
			if["$yORn" != "Y"]||["$yORn" != "y"]||["$yORn" != "n"]||["$yORn" != "N"]
			then
			echo
			echo "**** Error - Must input Y or N"
			fi

		done
		;;
	esac
   done 

if[$flag -eq 1]
then


functOne $num1 $num2 $num3
two = Function_Two $num1 $num2 $num3
echo 
echo "2) $num1 + $num2 + $num3 = $two"
echo
three = Function_Three $num1 $num2 $num3
echo "3) $num1 * $num2 * $num3 = $three"
echo
four = Function_Four $two
echo "4) ($num1 + $num2 + $num3) /3 = $four"
Function_Five $num1 $num2 $num3
Function_Six $num1 $num2 $num3
Function_Seven $num1 $num2 $num3
echo 
Function_Eight $num2
nine = Function_Nine $num1
echo
echo "10) Factorial of $num1 is: $nine"
echo
ten = Function_Ten $num3
	if[-z "$ten"] 
	then
	echo
	else
	echo "11) $num3 $ten"
	fi

fi


if[$flag -eq 1]
then
read -p 'Run the script again Y|N ----> ' yORn
	case "$yORn" in
	    Y | y)	echo
			read -p 'Enter 3 integer Values ----> ' num1 num2 num3
			echo
			;;

	    N | n)	flag = 0
			break
			;; 

	    *)	echo "**** Error - Must input Y or N"
		echo 
		while["$yORn" != "Y"]||["$yORn" != "y"]||["$yORn" != "n"]||["$yORn" != "N"];
		do
			read -p 'Run the script again Y|N ----> ' yORn
			if["$yORn" = "n"] || ["$yORn" = "N"]
			then
			flag=0
			fi
			
			if["$yORn" != "Y"]||["$yORn" != "y"]||["$yORn" != "n"]||["$yORn" != "N"]
			then
			echo
			echo "**** Error - Must input Y or N"
			fi

		done
		;;
	esac
done 


echo
echo "End of script"
echo "Implemented by Daisey Jaramillo - 9-23-2020"

exit 0
