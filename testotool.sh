
for file in $TEST_DIR
do
	diff <(./ft_otool $file) <(otool -t $file)
done
