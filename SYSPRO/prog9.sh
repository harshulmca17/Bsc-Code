compare()
{
echo ""
if cmp $f1 $f2
 then echo "Files are same. Removing 2nd file."
 rm -f $f2
 sleep 1s
else echo "Files are different."
fi
}

echo ""
echo "Enter the name of 1st file"
read f1
if test -s $f1
then echo "File one exists."
else echo "File one do not exists. Please try again later!"
exit 1
fi

echo ""
echo "Enter the name of 2nd file"
read f2
if test -s $f2
then echo "File two exists."
else echo "File two do not exists. Please try again later!"
exit 1
fi
compare
