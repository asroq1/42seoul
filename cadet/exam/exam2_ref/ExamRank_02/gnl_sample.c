//Assignment name : get_next_line
//Expected files : get_next_line.c get_next_line.h
//Allowed functions: read, free, malloc
//--------------------------------------------------------------------------------

//Write a function named get_next_line which prototype should be:
//char *get_next_line(int fd);


//Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

//The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

//In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

//Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

//Caling your function get_next_line in a lop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size od either the text or one of its lines.

//Make sure that your function behaves wel when it reads from a file, from the standard output, from a redirection, etc...

//No call to another function will be done on the file descriptor between 2 calls of get_next_line. Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.


#include <stdlib.h>
#include <unistd.h>
​
char *gnl(size_t size, int fd)
{
    char *ret, word_one = 0, read_word = read(fd, &word_one, 1);
    if (read_word < 0 || read_word == 0 && size == 0)
        return (NULL);
    if (read_word == 0 || word_one == '\n')
        ret = malloc(size + 2);
    else
        ret = gnl(size + 1, fd);
    if (ret)
    {
        ret[size] = word_one;
        ret[size + 1] = ret[size + 1] * (word_one != '\n');
    }
    return ret;
}
​
char *get_next_line(int fd)
{
    return (gnl(0, fd));
}
​
/*
// 원작자 : cjeon
// char *_(size_t a,int b){char*t,c=0,k=read(b,&c,1);if(k<0||k==0&&a==0)return NULL;if(k==0||c=='\n')t=malloc(a+2);else t=_(a+1,b);if(t)t[a]=c,t[a+1]=t[a+1]*(c!='\n'); return t;}
// char *get_next_line(int fd){return _(0,fd);}
*/