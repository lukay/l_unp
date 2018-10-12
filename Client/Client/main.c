//
//  main.c
//  Client
//
//  Created by LK on 2018/10/10.
//  Copyright © 2018 LK. All rights reserved.
//

#include "unp.h"

struct kktest {
    size_t fi;
    size_t sc;
    size_t th;
};

struct utest {
    size_t yi;
    size_t er;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    struct kktest tt;
//    tt.fi = 9;
//    tt.sc = 2;
//    tt.th = 3;
//
//    struct utest *ut;
//    ut = (struct utest *) &tt;
//
//    printf("%zu  %zu \n", ut->yi, ut->er);
//
//    return 0;
    
//    char *ptr = getenv("LISTENQ");
//    if (ptr == NULL) {
//        printf("null");
//    }
//    printf("%s", ptr);
//    return 0;
    
    int                    sockfd, n;
    char                recvline[MAXLINE + 1];
    struct sockaddr_in    servaddr;
    
    if (argc != 2)
        err_quit("usage: a.out <IPaddress>");
    
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(9999);    /* daytime server */
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_quit("inet_pton error for %s", argv[1]);
    
    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
        err_sys("connect error");
    
    while ( (n = (int)read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;    /* null terminate */
        if (fputs(recvline, stdout) == EOF)
            err_sys("fputs error");
    }
    if (n < 0)
        err_sys("read error");
    
    exit(0);
}
