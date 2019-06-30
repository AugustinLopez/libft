make -C ../../../
gcc behavior_memset.c ../../../libft.a -I../../../includes -o behavior
printf 'test CHAR\n'
./behavior 0
printf 'test SIZE\n'
./behavior 1
printf 'test NULL_PTR\n'
./behavior 2
printf 'test NULL_LEN\n'
./behavior 2
printf 'test MEMORY_ACCESS\n'
./behavior 4
rm ./behavior
