#include <arpa/inet.h>
// #include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include "proxy_parse.h"
#define MAX_CLIENTS 10


struct cache_element {
	char *data;
	size_t dLen;
	char *url;
	time_t lruTime;
	struct cache_element *next_element;
};

int port_number = 8080;
int proxy_socketId;
void remove_cache_element(void);
struct cache_element *find(const char *url);
int add_data(const char *data, const size_t d_len, const char *url);

pthread_t users[MAX_CLIENTS];
sem_t semaphore;
pthread_mutex_t lock;

struct cache_element *head = NULL;

int main(const int argc, const char *const argv[]) {
	int client_socketID = 0;
	int client_len      = 0;

	struct sockaddr_in server_addr, client_addr;
	sem_init(&semaphore, 0, MAX_CLIENTS);
	pthread_mutex_init(&lock, NULL);

	if (argc == 2) {
		port_number = atoi(argv[1]);
	} else {
		fprintf(stderr, "Too few arguments\n");
		exit(1);
	}

	printf("Starting proxy server at %d\n", port_number);
	proxy_socketId = socket(AF_INET, SOCK_STREAM, 0);

	if (proxy_socketId < 0) {
		perror("Faild to create the socket\n");
		exit(1);
	}

	int reuse = 1;
	if (setsockopt(proxy_socketId, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse,
	               sizeof(reuse)) < 0) {
		perror("setsockopt failed\n");
	}

	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family      = AF_INET;
	server_addr.sin_port        = htons(port_number);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(proxy_socketId, (struct sockaddr *)&server_addr,
	         sizeof(server_addr)) < 0) {
		perror("Port is not avaiable\n");
		exit(1);
	} else {
		printf("Banding on port %d\n", port_number);
	}

	int listen_status = listen(proxy_socketId, MAX_CLIENTS);
	if (listen_status < 0) {
		perror("Error in listening\n");
	}

	int i         = 0;
	int connected_socketID  = 0;

	return 0;
}
