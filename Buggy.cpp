/*Steps To identify the issue : 
1- Run the strace -c ./Buggy :There is an error at  openat 
2- Run the strace ./Buggy There is an error at return of system call openat which return -1 No such file or directory 
3- Sample.txt is not exist 
Solution 
1- Use #include<fcntl.h> defines constants used with system calls like open, fcntl, and creat for specifying file access modes and flags.
2- Use open()   with flag O_WRONLY | O_CREAT | O_TRUNC: Open the file for writing, create it if it doesn’t exist, and truncate it to zero length if it does.
3- Use open() with access modes _IRWXU | S_IRWXG | S_IRWXO: File permission flags for:
S_IRWXU: Read, write, execute for the owner.
S_IRWXG: Read, write, execute for the group.
S_IRWXO: Read, write, execute for others.

Result : 
1-The normal compilation of the file without compilation error. 
2-The program executed in normal way without error "Error: File not found!"
3-Execute the strace-c ./Buggy there is no errors at openAt and also no permission erros.
4- Execute the strace ./Buggy there is no errors at file execution

*/
#include <iostream>

#include <fstream>

#include <string>

// Add the right include to use flags macros 
#include<fcntl.h>
 

int main() 
{

    //  O_CREAT : If pathname does not exist, create it as a regular file.

    int fd = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);

    //create object from file to read from file sample.txt which is not exist
    std::ifstream file("sample.txt");

    //Check if the file opject is opened
    if (!file.is_open()) {

        std::cerr << "Error: File not found!\n";

        return 1;

    }

 

    std::string line;

    while (std::getline(file, line)) {

        std::cout << line << "\n";

    }

 

    file.close();

    return 0;

}