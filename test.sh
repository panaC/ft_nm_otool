
for file in $TEST_DIR
do
	diff <(./ft_nm $file) <(nm $file)
done
