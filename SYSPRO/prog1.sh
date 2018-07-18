argc=$#
for((i=argc;i>=1;i--))
do
eval "j=\${$i}"
echo -n " " $j
done
