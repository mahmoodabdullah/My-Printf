# My-Printf
This project uses the stdarg.h library to manage variable arguments. It loops through the format string and detects % specifiers, then uses a switch statement to call helper functions for each type. For example, num_to_str handles %d, while separate functions manage %x and %X, keeping conversions clean and efficient.
