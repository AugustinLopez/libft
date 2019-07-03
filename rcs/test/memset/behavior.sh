make -C ../../../
gcc behavior_memset.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
printf 'GENERAL -        '
./behavior 0
printf '\nLIMITED MEMORY - '
./behavior 1
printf 'System result is '
./behavior 2
printf '\nNULL,X,0 -       '
./behavior 3
printf 'System result is '
./behavior 4
printf '\nNULL,X,1 -       '
./behavior 5
printf 'System result is '
./behavior 6
printf '\nUNAUTHORIZED -   '
./behavior 7
printf 'System result is '
./behavior 8
rm ./behavior
