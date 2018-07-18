menu()
{
 echo "1. Display last n number of lines from the file."
 echo "2. Sort in ascending order"
 echo "3. Sort in descending order"
 read choice
 case $choice in
 1*) ch_one;;
 2*) ch_two;;
 3*) ch_three;;
 esac
}

ch_one()
{
  echo "Enter the number of lines which you want to print:"
  read n
  cat $fname | tail -$n
  continueornot
}

ch_two()
{
 echo "Sorting in Ascending Order..."
 sleep 2s
 cat $fname | sort > out.txt
 cat out.txt
 rm -rf out.txt
 continueornot
}

ch_three()
{
 echo "Sorting in Descending Order..."
 sleep 2s
 cat $fname | sort -r > out2.txt
 cat out2.txt
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

continueornot()
{
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
