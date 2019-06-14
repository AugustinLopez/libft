make -C ../../../
gcc main_memset.c ../../../libft.a -I../../../includes -o test_memset
printf 'test CHAR\n'
./test_memset 0
printf 'test SIZE\n'
./test_memset 1
printf 'test NULL_PTR\n'
./test_memset 2
printf 'test NULL_LEN\n'
./test_memset 2
printf 'test PERFORMANCE\n'
./test_memset 4
rm ./test_memset
