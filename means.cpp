#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<fstream>
#include<iostream>
using namespace std;

double arithmetric_mean(double* arr, int length){
    double sum = 0;
    for(int i = 0; i < length; i++){
        sum += arr[i];
    }
    double am = sum / length;
    return am;
}

double AM(double a, double b){
    double* arr = new double[2];
    arr[0] = a;
    arr[1] = b;
    int length = 2;
    return arithmetric_mean(arr, length);
}

double geometric_mean(double* arr, int length){
    double prod = 1;
    for(int i = 0; i < length; i++){
        prod *= arr[i];
    }
    double t = 1 / (double)length;
    // printf("prod: %f\nlength: %f\n", prod, t);
    double gm = pow(prod, t);
    // printf("gm: %f\n", gm);
    return gm;
}

double GM(double a, double b){
    double* arr = new double[2];
    arr[0] = a;
    arr[1] = b;
    int length = 2;
    return geometric_mean(arr, length);
}

// relationship between HM and AM: HA is the reciprocal of (AM of the reciprocals)
double harmonic_mean(double* arr, int length){
    double* brr = new double[length];
    for(int i = 0; i < length; i++){
        brr[i] = 1 / arr[i];
    }
    double res = arithmetric_mean(brr, length);
    return 1 /res; 
}

double HM(double a, double b){
    double* arr = new double[2];
    arr[0] = a;
    arr[1] = b;
    int length = 2;
    return harmonic_mean(arr, length);
}

struct array_struct
{
    double* content;
    int length;
};

struct array_struct* get_array_struct(){
    struct array_struct* s = new struct array_struct;
    double* c = new double[100];
    s->content = c;
    std::ifstream infile("random_number.txt");
    double d;
    int t;
    int counter = 0;
    while (infile >> t)
    {
        d = (double)t / 100;
        // printf("%f\n", d);
        c[counter++] = d;
    }
    s->length = counter;
    return s;
}

int main(){
    struct array_struct* s = get_array_struct();

    // for(int i = 0; i < s->length; i++){
    //     printf("%d: %f\n", i, s->content[i]);
    // }
    // printf("s->length: %d\n", s->length);
    double am = arithmetric_mean(s->content, s->length);
    double gm = geometric_mean(s->content, s->length);
    double hm = harmonic_mean(s->content, s->length);
    printf("Arithmetic Mean: %f\n", am);
    printf("Geometric Mean: %f\n", gm);
    printf("Harmonic Mean: %f\n", hm);

    free(s->content);
    free(s);


    cout << "The arithmetic mean of 3 and 5 is: " << AM(3,5) << endl;
    cout << "The geometric  mean of 3 and 5 is: " << GM(3,5) << endl;
    cout << "The harmonic   mean of 3 and 5 is: " << HM(3,5) << endl;
    return 0;
}