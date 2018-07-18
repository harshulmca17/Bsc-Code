run()
{
if test -s $fname
then
   echo "FILE IS NON EMPTY"
   echo "#########################################"
   echo "Original File :"
   echo " "
   cat $fname
   echo " "
   echo "#########################################" 
   echo " "
   echo "Now removing multiple spaces and tabs..."
   echo " "
   sleep 1s
   cat $fname | tr -t "\n" "*" | tr -t "\t" "&" | tr -s " " "@"| tr -s "\t"| tr -t "\t" " " | tr -s " " | tr -s "\n" > out.txt
   echo "The modified file is :"
   cat out.txt
   echo " " 
   rm -rf out.txt
else
   echo "FILE IS EMPTY or DOES NOT EXIST!"
fi
}

echo "Enter the filename from which you want to eliminate spaces and tabs:"
read fname
run
