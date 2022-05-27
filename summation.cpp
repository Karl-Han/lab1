#include<stdio.h>
#include<sys/time.h>

int sumV1(int n){
    int sum = (1 + n)*n / 2;
    return sum;
}

int sumV2(int n){
    int sum = 0;
    while(n > 0){
        sum += n;
        n--;
    }
    return sum;
}

long int get_time(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
}

int main(){
    int size[5] = {0x1<<6, 0x1<<12, 0x1<<28, 0x1<<30, __INT_MAX__};
    int s = 5;
    long int timeV1[s];
    long int timeV2[s];
    for(int i = 0; i < s; i++){
        long int beforeV1 = get_time();
        sumV1(size[i]);
        long int afterV1 = get_time();
        sumV2(size[i]);
        long int afterV2 = get_time();
        timeV1[i] = afterV1 - beforeV1;
        timeV2[i] = afterV2 - afterV1;
    }
    
    for(int i = 0; i < s; i++){
        printf("%ld,", timeV1[i]);
    }
    printf("\n");
    for(int i = 0; i < s; i++){
        printf("%ld,", timeV2[i]);
    }

    return 0;
}