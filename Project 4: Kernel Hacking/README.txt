This file contains the instructions to running and testing the program(s) in this assignment

Project 4: Kernel Hacking
This project is a bit different from the other two in that it uses a lot of different files and cannot be used directly from the terminal.
First you need to install qemu and xv6 if you have these two installed you can skip to running the app. First navigate to the folder you want to install xv6 to.
In the terminal in that folder use command 'sudo apt install qemu', reate a directory and use the command 'git clone git://github.com/mit-pdos/xv6-public.git'.
This clones all the necessary files to your computer to use the default xv6 environment.

Running the app
You need to copy all the files in this folder to your xv6 folder except this README.txt file.
All files except the 'getreadcount.c' will replace an old file in the folder but that is fine since they are the original files just with minor tweaks.
Then run the command 'make qemu' and then in qemu run 'ls' to see the getreadcount command in there. Running the 'getreadcount' system call will give you the
number of read system calls that have been called in your current qemu session.

This project was made and tested in a virtual Ubuntu environment using the xv6 environment and the qemu interface.
