# Welcome to My Printf
***

## Task
The primary task is to create a custom version of the standard C library's printf function. 
The main challenge is handling a variable number of arguments and correctly interpreting the 
format string to print different data types such as integers, characters, strings, and hexadecimal values. 
This requires writing custom helper functions to convert numbers and pointers into their string 
representations without relying on built-in library functions.

## Description
This project solves the problem by using the stdarg.h library 
to handle the variable arguments passed to the function. 
A main loop iterates through the format string character by character. 
When a % character is encountered, the code checks the subsequent character to 
identify the format specifier. A switch statement then dispatches the logic to a specific 
helper function for each type. For instance, num_to_str handles signed integers (%d), 
while separate functions like hex_to_str_lower and hex_to_str_upper are used to manage 
the different case requirements for %x and %X respectively. This modular approach ensures each 
data conversion is handled cleanly and efficiently.

## Installation
To use this project, you just need a C compiler. 
There is no complex installation or external dependencies. 
You can simply compile the C source file using the gcc command.
For example, to compile your my_printf.c file and create an executable named my_printf, 
you can use the following command in your terminal:

Bash

gcc my_printf.c -o my_printf

## Usage
Once the project is compiled, you can run the executable directly from your terminal. 
You can call the my_printf function from your main function just like the standard printf, 
passing a format string and the corresponding arguments.

To run a simple test case, your main function might look like this:

C

int main(void)
{
    char *name = "World";
    int num = 42;
    unsigned int u_num = 12345;
    int hex_val = 255;
    char my_char = 'A';

    my_printf("Hello, %s! The number is %d.\n", name, num);
    my_printf("Unsigned: %u, Octal: %o, Hex lower: %x, Hex upper: %X\n", u_num, u_num, hex_val, hex_val);
    my_printf("Character: %c, Percent: %%\n", my_char);
    
    return 0;
}
After compiling with gcc my_printf.c -o my_printf, you would execute it from the command line:

Bash

./my_printf

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
