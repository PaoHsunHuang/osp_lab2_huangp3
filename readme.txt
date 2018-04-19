include function:
./new_cat
./new_echo
./new_tail
./new_wc
makefile

description:
() parameter is option

new_cat (filename.txt)
if user input filename, it will print out the txt insude
or read from the stdin, and repeat what user input

new_echo (arg)(arg)(arg)
user can enter as many argument as they want
it will repeat what user type in argument or the input from stdin

user_tail (-n num)(filename.txt)
Both upper and lower -n will work 
the order of flag and file doesn't matter,
but -n have to follow by a number
it will read the file or user input and print the last few line
of the text file
the default line number is 5, can be changed by -n

user_wc (-l | -C)(filename.txt)
can only choose either -l or -c, upper or lower case doesn't matter
-c only printout the number of character
-l only printout the number of line
the order of flag and file doesn't matter,
if there is a file count the number in file, if not count the number
of stdin
without -l or -c, will print word, character and line number
