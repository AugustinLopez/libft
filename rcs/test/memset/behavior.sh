make -C ../../../
gcc behavior_memset.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
printf 'GENERAL -        '
./behavior 0 $1
printf '\nLIMITED MEMORY - '
./behavior 1 $1
printf 'System result is '
./behavior 2 $1
printf '\nNULL,X,0 -       '
./behavior 3 $1
printf 'System result is '
./behavior 4 $1
printf '\nNULL,X,1 -       '
./behavior 5 $1
printf 'System result is '
./behavior 6 $1
printf '\nUNAUTHORIZED -   '
./behavior 7 $1
printf 'System result is '
./behavior 8 $1
