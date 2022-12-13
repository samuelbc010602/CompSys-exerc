#include <time.h>

int main(int argc, char **argv) 
{
    int clientfd;
    char *host, *port, buf[MAXLINE];
    char * emptyString = "";
    rio_t rio;

    clock_t start, end;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    printf("This program will attempt to send a string to a server. Type one "
        "here and hit enter to send: ");
    while (Fgets(buf, MAXLINE, stdin) != NULL) {
	start = clock();
        Rio_writen(clientfd, buf, strlen(buf));
        Rio_readlineb(&rio, buf, MAXLINE);
        printf("Recieved reply: ");
        Fputs(buf, stdout);
        printf("Enter another string: ");

	
	if(strcmp(buf,emptyString) != 0){
	    
	    


	
	
    }
    Close(clientfd); //line:netp:echoclient:close
    exit(0);
}
