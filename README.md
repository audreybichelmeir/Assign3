# Assignment2
Data Structures Assignment1

Full name: Audrey Bichelmeir
Student ID: 2327865
Chapman email: bichelmeir@chapman.edu
Course number and section: Cpsc350 -02
Assignment or exercise number: assignment3
Files submitted:
main.cpp
GenStack.h
fileReader.cpp
fileReader.h
correct1.txt
correct2.txt
incorrect1.txt
incorrect2.txt
incorrect3.txt

running the program
make all
make realclean
without make file g++ *.cpp
./a.out textfile



References:
• GenStack - Rene

• Michael T Goodrich, Roberto Tamassia, David M Mount - Data structures and algorithms in C++-Wiley (2011) page 205
used textbook for general outline

• Walter Savitch, Kenrick Mock - Absolute C++-Addison-Wesley (2012) page 85 & 86
general reading from a file

• Michael Main, Walter Savitch - Data Structures and Other Objects Using C++ (4th Edition)-Pearson (2010) page 203 & 357
general understand of getting a line to check delimiter
easy code but returns a boolean (general idea)

Ryan Millares
Pair function()
general printing out statements

Peter Chen
General Logic -- understanding first one must push then same pop it.

Known Error
correct1.txt prints out Perfectly balanced, as things should be twice it should only be once... if I change the isEmpty at line 89 and error will happen

the file will run if the user types out the file (e.g. correct1.txt) sometimes if the the up button is pressed with an incorrect text file
ex.
./a.out incorrect1.txt
./a.out incorrect2.txt
./a.out incorrect3.txt
./a.out incorrect1.txt (up arrow for this is fine)
./a.out incorrect2.txt (up arrow for this is fine)
./a.out incorrect3.txt (up arrow for this is NOT fine)

works to some extent
it will run BUT after user will get this
*** Error in `./a.out': free(): invalid pointer: 0x00007ff5e49e3980 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x70bfb)[0x7ff5e3e1bbfb]
/lib/x86_64-linux-gnu/libc.so.6(+0x76fc6)[0x7ff5e3e21fc6]
/lib/x86_64-linux-gnu/libc.so.6(+0x7780e)[0x7ff5e3e2280e]
./a.out(+0x21b1)[0x55f55c87c1b1]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf1)[0x7ff5e3dcb2e1]
./a.out(+0x13ea)[0x55f55c87b3ea]
======= Memory map: ========

etc....
