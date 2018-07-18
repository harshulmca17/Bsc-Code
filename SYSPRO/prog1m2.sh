argv=$*
argc=$#
for((i=1;i<=argc;i++))
do
((n=argc-i))
shift $n
set $argv
echo $i
done
