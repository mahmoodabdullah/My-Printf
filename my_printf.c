#include <unistd.h>
#include <stdarg.h>


int str_len(char *s)
{
    int i = 0;
    if (s == NULL)
        return 0;

    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int hex_to_str(unsigned int x) 
{
    int count = 0;
    char buffer[12];
    int i = 0;
    int rem;

    if (x == 0)
    {
        write(1, "0", 1);
        return 1;
    }
    while (x > 0)
    {
        rem = x % 16;
        if (rem < 10)
        {
            buffer[i++] = rem + '0';
        }
        else 
        {
            buffer[i++] = rem - 10 + 'A';
        }
        x /= 16;
    }

    count += i;

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
    }

    return count;
}

int octal_to_str(unsigned int o) 
{
    int count = 0;
    char buffer[12];
    int i = 0;

    if (o == 0)
    {
        write(1, "0", 1);
        return 1;
    }
    while (o > 0)
    {
        buffer[i++] = (o % 8) + '0';
        o /= 8;
    }

    count += i;

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
    }

    return count;
}

int unsigned_to_str(unsigned int u) 
{
    int count = 0;
    char buffer[12];
    int i = 0;

    if (u == 0)
    {
        write(1, "0", 1);
        return 1;
    }
    while (u > 0)
    {
        buffer[i++] = (u % 10) + '0';
        u /= 10;
    }

    count += i;

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
    }

    return count;
}

int num_to_str(int n)
{
    int count = 0;
    char buffer[12];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }
    if (n < 0)
    {
        unsigned int n_unsigned = -n;
        write(1, "-", 1);
        count++;

        while (n_unsigned > 0)
        {
            buffer[i++] = (n_unsigned % 10) + '0';
            n_unsigned /= 10;
        }
    }
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }
    
    count += i;

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
    }

    return count;
}

int ptr_to_str(void *ptr)
{
    int count = 0;
    char buffer[16]; 
    int i = 0;
    unsigned long int address = (unsigned long int)ptr;

    if (ptr == NULL)
    {
        write(1, "(nil)", 5);
        return 5;
    }

    count += write(1, "0x", 2);

    if (address == 0)
    {
        write(1, "0", 1);
        return count + 1;
    }

    while (address > 0)
    {
        int rem = address % 16;
        if (rem < 10)
        {
            buffer[i++] = rem + '0';
        }
        else
        {
            buffer[i++] = rem - 10 + 'a';
        }
        address /= 16;
    }
    
    count += i;

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
    }
    
    return count;
}

int my_printf(const char *format, ...)
{
    int count = 0;

    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '%')
            {
                write(1, &format[i], 1);
                count++;
                i++;
            }
            else if (format[i + 1] == 's')
            {
                char *s = va_arg(args, char *);
                if (s == NULL)
                {
                    write(1, "(null)", 6);
                    count += 6;
                }
                else
                {
                    int len = str_len(s);
                    write(1, s, len);
                    count += len;
                }
                i++;
            }
            else if (format[i + 1] == 'd')
            {
                int num = va_arg(args, int);
                count += num_to_str(num);
                i++;
            }
            else if (format[i + 1] == 'c')
            {
                int c = va_arg(args, int);
                write(1, &c, 1);
                count++;
                i++;
            }
            else if(format[i + 1] == 'u')
            {
                unsigned int un_num = va_arg(args, unsigned int);
                count += unsigned_to_str(un_num);
                i++;
            }
            else if(format[i + 1] == 'o')
            {
                unsigned int oct_num = va_arg(args, unsigned int);
                count += octal_to_str(oct_num);
                i++;
            }
            else if(format[i + 1] == 'x')
            {
                unsigned int hex_num = va_arg(args, unsigned int); 
                count += hex_to_str(hex_num);
                i++;
            }
            else if(format[i + 1] == 'p')
            {
                void *ptr = va_arg(args, void *);
                count += ptr_to_str(ptr);
                i++;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
    }

    va_end(args);
    return count;
}