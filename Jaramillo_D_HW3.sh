# !/bin/sh
# NAME: Daisey Jaramillo
# CS4350-Unix Systems Programming
# Assignment Number: 3
# Due Date: 10/5/2020 No later than 5:15pm

createDir(){
	  mkdir ZHW3
	  ls -l
	  echo  
}

createFile(){
	if [[ -f "ZHW3/password.txt" ]]
	then
	   return
	else
	   touch ZHW3/password.txt
	fi

}

evaluatePass(){
	if test ${#string1} -lt 8
	then
	   echo \<Weak Password\>
	   return	
	fi

	if [[ $string1 =~ [0-9] ]]
	then 
	   echo
	else
	   echo   
	   echo \<Weak Password\>
	   return 
	fi

	if [[ $string1 =~ [a-z] ]] && [[ $string1 =~ [A-Z] ]]
	then
	   echo
	else 
	   echo \<Weak Password\>
	   return
	fi

	if [[ $string1 == *[@'#'$%'&'*]* ]]
	then
	  echo 
	else
	  echo \<Weak Password\>
	  return
	fi	


	echo \<Strong Password\>
        createFile
	echo $string1 > ./ZHW3/password.txt			
}

deleteStuff(){
	
	if [[ -f "ZHW3/password.txt" ]]
	then
	   rm ./ZHW3/password.txt
	   echo
	   echo password.txt file is deleted
		if [[ -f "ZHW3/password.txt" ]]
		then
		   echo PASSWORD.TXT STILL EXISTS
		else
	  	   echo password.txt file does not exist
		fi
	else
	   echo password.txt file does not exist
	fi


	rmdir ZHW3
	echo ZHW3 directory is deleted
	if [[ -d "./ZHW3" ]]
	then
	   echo ZHW3 STILL EXISTS
	else
	   echo ZHW3 does not exist
	fi	
	
}

string1=$1
echo
echo Opportunities to write scripts in UNIX
echo  

createDir
evaluatePass

while true
 do
read -r -p " Try another password --- \> Yy\|Nn --- \> " InpuT
case "$InpuT" in
	Y|y)
	    read -r -p "Enter new password :-- \>  " string1
	    evaluatePass 
	    ;;
	N|n)
	    break
 	    ;;
	*)
	  echo \*\*\*\* Incorrect Selection - Must select Y or N
	    ;;
esac
done

echo The content of the password file is : 
echo
cat ZHW3/password.txt
deleteStuff
echo
echo Implemented by Daisey Jaramillo - 10-5-2020
echo
exit 0
