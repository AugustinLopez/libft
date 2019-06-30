make -C ../../../
gcc behavior_memset.c ../../../libft.a -I../../../includes -o behavior
printf 'CHAR -          '
./behavior 0
printf 'SIZE -          '
./behavior 1
printf 'NULL_PTR -      '
./behavior 2
printf 'MEMORY_ACCESS - '
./behavior 3
rm ./behavior
