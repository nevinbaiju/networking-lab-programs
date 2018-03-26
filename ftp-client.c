
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <fcntl.h>
    int main(int arc, char * argv[]) {
        struct sockaddr_in address;
        int sock_descr;
        int k, choice, len, l, c = 0, filehandle;
        char buf[100], length[100], fil[100], filename[100];
        memset( &address, 0, sizeof(address));
        sock_descr = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_descr == -1) {
            printf("socket creation failed");
            exit(1);
        }
        address.sin_family = AF_INET;
        address.sin_port = 3001;
        address.sin_addr.s_addr = INADDR_ANY;
        k = connect(sock_descr, (struct sockaddr * ) &address, sizeof(address));
        if (k == -1) {
            printf("connecting failed");
            exit(1);
        }
        while (1) {
            printf("\n1:LIST\n2:LOAD\n3:Exit : ");
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                filehandle = open("list2.txt", O_RDWR | O_CREAT, 0700);
                strcpy(buf, "LIST");
                k = send(sock_descr, buf, strlen(buf), 0);
                if (k == -1) {
                    printf("send failed");
                    exit(1);
                }
                k = recv(sock_descr, length, 100, 0);
                if (k == -1) {
                    printf("receive failed");
                    exit(1);
                }
                len = atoi(length);
                while (c < len) {
                    l = read(sock_descr, fil, 100);
                    if (l == 0)
                        break;
                    write(filehandle, fil, 100);
                    c += l;
                }
                system("cat list2.txt");
                close(filehandle);
                break;
            case 2:
                strcpy(buf, "LOAD");
                printf("Enter filename : ");
                scanf("%s", filename);
                filehandle = open(filename, O_RDWR | O_CREAT, 0700);
                strcat(buf, filename);
                k = send(sock_descr, buf, sizeof(buf), 0);
                if (k == -1) {
                    printf("send failed");
                    exit(1);
                }
                k = recv(sock_descr, length, 100, 0);
                if (k == -1) {
                    printf("receive failed");
                    exit(1);
                }
                len = atoi(length);
                c = 0;
                printf("This is the value of len %d\n", len);
                while (c < len) {
                    l = read(sock_descr, fil, strlen(fil));
                    if (l == 0)
                        break;
                    printf("Ivde onnum oru scenumilla%d\n", l);
                    printf("This is the value of c %d\n", c);
                    write(filehandle, fil, strlen(fil));
                    c += l;
                    printf("Ivde entho scene und");
                    break;
                }
                printf("Alla Ivde aanu entho scene");
                system("cat list3.txt");
                printf("But ivde no scene");
                break;
            case 3:
                exit(0);
            default:
                break;
            }
        }
        return 0;
    }