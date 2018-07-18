menu()
{
 echo " "
 echo "CHOOSE FROM THE FOLLOWING OPTIONS:"
 echo "1. Display the file."
 echo "2. Display the permission of the file."
 echo "3. Find a specific pattern in the file (ignore case)."
 echo "4. Find a specific pattern in the file (case sensitive)."
 echo "5. Replace all 'e' by 'a'."
 echo " "
 read choice
 case $choice in
 1) ch_one;;
 2) ch_two;;
 3) ch_three;;
 4) ch_four;;
 5) ch_five;;
 *) echo "Wrong Choice!"
  run;;
 esac
}

ch_one ()
{
  echo "Your File:"
  echo "------------------------------------------------------"
  cat $fname
  echo "------------------------------------------------------"
  continueornot
}

ch_two ()
{
 res= ` ls -l $fname | cut -d " " -f1`
 cat out.txt
 rm -rf out.txt
 continueornot
}

ch_three ()
{
 echo " "
 echo "Enter the pattern you want to search in the file:"
 read pattern
 cat $fname | grep $pattern -i > out2.txt
 cat out2.txt
 rm -rf out2.txt
 continueornot
}

ch_four ()
{
 echo " "
 echo "Enter the pattern you want to search in the file:"
 read pattern
 cat $fname | grep $pattern > out2.txt
 cat out2.txt
 rm -rf out2.txt
 continueornot
}

ch_five ()
{
 echo ""
 echo "Converting all 'e' to 'a' (CASE SENSITIVE)..."
 sleep 1s
 cat $fname | tr 'e' 'a' > out.txt
 cat out.txt
 rm -rf out.txt
 continueornot
}

run()
{
  if test -s $fname
  then
    menu
  else
   echo "No Such File exists or file empty!"
   exit 1
  fi
}

continueornot ()
{
 echo " " 
 echo "Do you want to continue or not?"
 read reply
 case $reply in
 y*|Y*) menu;;
 n*|N*) exit 1;;
 *) echo "Wrong choice"
 esac
}

echo "Enter the filename:"
read fname
run
