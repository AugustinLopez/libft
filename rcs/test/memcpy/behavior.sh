make -C ../../../
gcc behavior_memcpy.c ../../../libft.a -I../../../includes -o behavior
printf 'GENERAL :       '
./behavior 0
printf 'MEMORY ACCESS : '
./behavior 1
printf 'SEGFAULT 1 :    '
./behavior 2
printf 'SEGFAULT 2 :    '
./behavior 4
printf 'SEFGAULT 3 :    '
./behavior 5
printf 'NO REACTION :   '
./behavior 6
printf 'MISALIGNED :    '
./behavior 7
rm ./behavior
