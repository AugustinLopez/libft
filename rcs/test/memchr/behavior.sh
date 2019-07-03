make -C ../../../
gcc behavior_memchr.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
printf 'CHAR -           '
./behavior 0
printf '\nSIZE -           '
./behavior 1
printf '\nMISALIGNED -     '
./behavior a
printf '\nLIMITED MEMORY - '
./behavior 2
printf 'System result is '
./behavior 3
printf '\nNULL, X, 0 -     '
./behavior 4
printf 'System result is '
./behavior 5
printf '\nNULL, X, 1 -     '
./behavior 6
printf 'System result is '
./behavior 7
printf '\nUNAUTHORIZED -   '
./behavior 8
printf 'System result is '
./behavior 9
rm ./behavior
