nclude<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

#define BUF_SIZE 1024

int main(int argc,char*argv[]){
	int fd_from,fd_to;ssize_t bytes_read,bytes_written;char buffer[BUF_SIZE];
	if(argc!=3){dprintf(2,"Usage: %s file_from file_to\n",argv[0]);exit(97);}
	fd_from=open(argv[1],O_RDONLY);if(fd_from==-1){dprintf(2,"Error: Can't read from file %s\n",argv[1]);exit(98);}
	fd_to=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0664);if(fd_to==-1){dprintf(2,"Error: Can't write to file %s\n",argv[2]);exit(99);}
	while((bytes_read=read(fd_from,buffer,BUF_SIZE))>0){bytes_written=write(fd_to,buffer,bytes_read);if(bytes_written!=bytes_read){dprintf(2,"Error: Can't write to file %s\n",argv[2]);exit(99);}}
	if(bytes_read==-1){dprintf(2,"Error: Can't read from file %s\n",argv[1]);exit(98);}
	if(close(fd_from)==-1||close(fd_to)==-1){dprintf(2,"Error: Can't close fd\n");exit(100);}

	return 0;
}
