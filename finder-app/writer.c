#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>

void 
print_usage_info (void) {
	printf("Usage: writer filepath string\n");
}

int
main(int argc, char **argv) {
    
	if (argc != 3) {
		print_usage_info();
		exit(EXIT_FAILURE);
	}

	int fd = 0;
	int err = 0;
	
	if ((fd = open(argv[1], O_RDWR|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO)) < 0) {
		perror("open");
		err = errno;
		syslog(LOG_USER|LOG_ERR, "Error in open: %s", strerror(err));
		exit(EXIT_FAILURE);
	}

	syslog(LOG_USER | LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

	int n = strlen(argv[2]);
	if (n != write(fd, argv[2], n)) {
		perror("write");
		err = errno;
		syslog(LOG_USER|LOG_ERR, "Error in write: %s", strerror(err));
		exit(EXIT_FAILURE);
	}
        
	return EXIT_SUCCESS;
}
