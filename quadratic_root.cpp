#include<stdio.h>
#include<cassert>
#include<cmath>

struct quadratic_root{
    double r1;
    double r2;
};

struct quadratic_root cal_quadratic_root(double a, double b, double c){
    double criteria = b*b - 4*a*c;
    if(criteria < 0){
        printf("quadratic root for %f*x^2 + %f*x + %f = 0 doesn't exist\n", a, b, c);
        abort();
    }
    struct quadratic_root qr;
    qr.r1 = (-b + pow(criteria, 0.5)) / (2 * a);
    qr.r2 = (-b - pow(criteria, 0.5)) / (2 * a);
    return qr;
}

void print_qr(struct quadratic_root qr){
    printf("Root1: %f\nRoot2: %f\n", qr.r1, qr.r2);
}

int main(){
    double a=2.0, b=5, c=3.1;
    struct quadratic_root qr = cal_quadratic_root(a, b, c);
    print_qr(qr);
    return 0;
}