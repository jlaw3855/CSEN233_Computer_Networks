Lab 1: Basic Linux, network commands, and C programming skills
Objectives
1. To review Linux/Unix commands.
2. To write sample C programs that demonstrate the use of system calls and files.

Guidelines
For all the labs, you need to develop a good knowledge of Linux/Unix commands and write C in a Linux
development environment. You are highly encouraged to use command-line tools in developing, compiling, and
running your programs. This Lab is designed to familiarize you with the basic Linux commands and programming
skills in C that you will need for the upcoming labs.
Please pay attention to your coding style and good programming practices; if your program is not worth
documenting, it probably isn't worth running.1 Please follow the GNU coding standards available at:
https://www.gnu.org/prep/standards/html_node/Writing-C.html.

Unix/ Linux
Linux is a Unix-like operating system, following the design principles of the Unix monolithic kernel in process
control, CPU scheduling, memory management, file systems, networking, and access to the peripherals. Please
read the details on https://en.wikipedia.org/wiki/Linux.
Unix/ Linux has had a culture of distinctive art and powerful design philosophy since its inception in
1969. Software technologies come and go, but Unix/ Linux remained dominant and continued to evolve on
various machines ranging from supercomputers and PCs to handheld devices and embedded networking
hardware. C language is ubiquitous and a central technology of Unix/ Linux. It is tough to imagine developing
applications at the core system level without C. The POSIX, Portable Operating System Standard, and the Unix
API (Application Programming Interface) are used to write genuinely portable software that can run across a
heterogeneous mix of computers. TCP/IP (which you will learn in this class) and Unix represent the core
technologies of the Internet.  On Linux, Mac OS, or Windows (cmd), you can use Linux commands in a terminal window, including the vi and
the gcc compiler.

Command-line
The use of command-line programs is a tradition in Unix\Linux. Commands are executable programs that can run
with various arguments (options). Command-line options are single letters preceded by a single hyphen, including:
-a: all, -b: buffer, -c: command, -d: debug, -e: execute, -f: file, -l: list, -o: output, -u: user
Some of the basic commands are:
- ls: lists all files and directories (try with options: -a, -al)
- cat: displays file content (try cat file1 file2 > file3)
- mv: moves a file to a new location (try mv file1 file2)
- rm: deletes a file
- cp: copy file
- man: gives helpful information on a command
- history: gives a list of past commands
- clear: clear the terminal
- mkdir: creates a new directory
- rmdir: deletes a directory
- echo: writes arguments to the standard output (try echo ‘Hello World’ > myfile)
- df: shows disk usage
- apt -get: install and update packages
- mail -s ‘subject’ -c ‘cc-address’ -b ‘bcc-address’ ‘to-address’ < filename: sends an email with an attachment
- chown/ chmod: change ownership/ permission of file or directory
- date: show the current date and time
- ps: displays active processes
- kill: kills the process
- sh: bourne shell – command interpreter (good to learn about shell programming)
- grep: searches for a pattern in files
- Ctrl+c: halts current command
- Ctrl+z: stops current command and resumes with foreground
- Ctrl+d (exit): logout of the current session
In general, you will probably use the commands - ls, more, mv, rm, mkdir, rmdir, cd, cp, chmod, who, ps, kill, ctrl+c, cmp, grep, cat, and man – more often. The man helps you to learn about a specific command and its use in Linux. For example, $man cat displays the meaning and usage of cat.

System Calls and Copying Files
System calls are often called kernel calls. They are c libraries that execute at the kernel level to allow users to interact with the operating system for services that include:
- Process creation and management (e.g. fork(), exec(), wait(), exit())
- File management (e.g. open(), read(), write(), close())
- Communication (e.g. pipe(), shmget(), mmap())
- Networking (e.g. socket(), bind(), connect(), listen(), sendto(), recvfrom())

Problem:
- Write a C program to copy binary/ text files simultaneously.
Analysis:
- Input: pass the file as arguments to main(), so your main function needs to be defined as follows:
int main(int argc, char * argv[])
Your files: src.dat and dest.dat files.
- File reading can be accomplished by using either:
o Functions: fopen, fwrite, and fread for binary files or fprintf and fscanf for text files
▪ FILE *fopen(const char *filename, const char *mode)
▪ fwrite( ptr, int size, int n, FILE *fp ); or fprintf() (for text files)
▪ fread( ptr, int size, int n, FILE *fp ); or fscanf() (for text files)
▪ fclose(ptr);
e.g.
FILE *fp;
fp = fopen(“src.dat”,"r”);
fp = fopen(“dest.dat","w”);
fwrite(&buf,1, sizeof(buf),fp);
fread(&buf,1,sizeof(buf),fp);
fclose(fp);

OR
o System calls: open, read, write
▪ int open (const char* Path, int flags [, int mode ]);
▪ size_t read (int fd, void* buf, size_t cnt);
▪ size_t write (int fd, void* buf, size_t cnt);
e.g.:
int fd = open("foo.txt", O_RDWR);
int nw = write(fd, buf, strlen(buf));
int nr = read(fd, buf, 40);
close (fd);
You need to include the following libraries:
▪ #include<sys/types.h>
▪ #include<sys/stat.h>
▪ #include <fcntl.h>

You may create files of random data with different sizes/ bytes. You may use “cat” and “head” commands ( i.e. $cat /dev/random | head -c <bytecount>). /dev/random are special files that serve as a pseudorandom number generator. “cat” is used to display the content, and “head” is used to display the specified number of lines. So, the result of “cat” is sent to the upstream end of PIPE, and “head” receives these results and redirects the content of the specified bytes to a file.

$cat /dev/random | head -c 100000 > src1.dat  creates a file with 100KB
$cat /dev/random | head -c 1000000 > src2.dat  creates a file with 1MB
Check the size of the files with the command “ls -la”

Once your program runs successfully:

Save and upload your Java source file(s) to the lab1_Basic_Linux_network_commands_c_programming_skills directory on GitHub (See the GitHub Setup Guide in Module 1).
Take screenshots of the program running and showing the results of your C programs.
References:
1- Eric S. Raymond, The Art of Unix Programming, Pearson, 2004
2- Jonathan Nagler, "Coding Style and Good Computing Practices”, PS: Political Science and Politics, Volume 28, Issue 3, 1995, pp. 488-492.
