#include<stdio.h>
#include<string.h>
#include<proxy_parse.h>
#include<time.h>
#include <pthread.h>

//  time based LRU cache remove least used cache 
// cache element is linked list 

#define MAX_CLIENTS 10

typedef struct cache_element cache_element ;

struct cache_element{
    char* data;
    int len;
    char* url;
    time_t lru_time_track;
    cache_element* next;
};

// for finding next elemnt 

cache_element* find(char* url);
int add_cache_element(char*data, int size, char* url);
void remove_cache_element();

int port_number = 8080; // for web server port num
int proxy_socketID;
pthread_t tid[MAX_CLIENTS]; // thread initialization


