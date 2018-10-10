//
//  main.c
//  Server
//
//  Created by LK on 2018/10/10.
//  Copyright © 2018 LK. All rights reserved.
//

#include <stdio.h>
#include "unp.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int                    listenfd, connfd;
    struct sockaddr_in    servaddr;
    char                buff[MAXLINE];
    time_t                ticks;
    
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(13);    /* daytime server */
    
    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    
    Listen(listenfd, LISTENQ);
    
    for ( ; ; ) {
        connfd = Accept(listenfd, (SA *) NULL, NULL);
        
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));
        
        Close(connfd);
    }
}
