ch1()
{
 echo ""
 echo "Now enter the content to overwrite. Press ctrl + D when done."
 cat > $fname
}

ch2()
{
 echo ""
 echo "Now enter the content to append. Press ctrl + D when done."
 cat >> $fname
}

check()
{
if test -d $fname
 then 
 echo " "
 echo "Entered File Name is a directory!"

elif test -f $fname
 then 
 echo " "
 echo "File exists and is non empty."
 run

else 
 echo ""
 echo "Entered file/directory does not exist."

fi
}

run()
{
 echo ""
 echo "Choose from the following options:"
 echo "1. Overwrite the contents of the file"
 echo "2. Append the content in the previous content"
 echo "3. Display the file."
 read ch
 case $ch in 
 1) ch1;;
 2) ch2;;
 3) echo ""
    cat $fname
     echo " " ;;
 *) echo "Wrong option! Try again."
 esac
 continueornot
}

continueornot()
{
 echo ""
 echo "Do you want to continue or not?"
 read reply
 case $reply in
 Y*|y*) run;;
 n*|N*) exit 1;;
 *) echo "Wrong Choice. Please Try again.";;
 esac
}

echo "Enter the name of the file or directory:"
read fname
check
