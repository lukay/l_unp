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
    
    int                    sockfd;
    struct sockaddr_in    servaddr;
    
    if (argc != 2)
        err_quit("usage: tcpcli <IPaddress>");
    
    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    
    Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
    
    str_cli(stdin, sockfd);        /* do it all */
    
    exit(0);
}
