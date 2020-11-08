#include <iostream>
#include <cmath>
using namespace std;
const long loops = 10000;
int interval[10];
void quater1_0(double gen){
    for (int i = 0; i < 10; i++){
        if(((gen >= (double) i/10) && (gen< (double)(i+1)/10)) || (gen == 1 && i == 9)){
            interval[i]++;
        }
    }
}
void quater3_3(double gen){
    for (int i = -5; i < 5; i++){
        if(((gen >= (double) i*0.6) && (gen< (double)(i+1)*0.6)) || (gen == 3 && i == 4)){
            interval[i+5]++;
        }
    }
}
void quater0_100(double gen){
    for (int i = 0; i < 10; i++){
        if(((gen >= (double) i*10) && (gen< (double)(i+1)*10)) || (gen == 100 && i == 9)){
            interval[i]++;
        }
    }
}
void generate_1(){
    long long a=113, c=257, m=16843, x0=3, xi;
    double u;
    for (int i = 0; i<loops; i++){
        xi = (a* x0 + c) % m;
        x0 = xi;
        u = (double) xi/(m-1);
        quater1_0(u);
    }
}

void generate_2(){
    long long a= 2, c=237, d= 1, m=2147483647, x0=7, xi;
    double u;
    for (int i = 0; i<loops; i++){
        xi = (d*x0*x0 + a*x0+c) % m;
        x0 = xi;
        u = (double) xi/(m-1);
        quater1_0(u);
    }
}

void generate_3() {
    long long x0 = 1, x1 = 1, m = 1019, xi;
    double u;
    for (int i = 0; i < loops; i++) {
        xi = (x0 + x1) % m;
        x0 = x1;
        x1 = xi;
        u = (double) xi / (m - 1);
        quater1_0(u);
    }
}
void generate_4(){
    long long a=13, c=17, p= 1117, x0=2, xo, xi;
    double u;
    for(int i = 0; i < loops; i++){
        int j = 0;
        while ((x0 * j) % p != 1){
            j++;
        }
        xo=j;
        xi = (a* xo + c) % p;
        x0 = xi;
        u = (double) xi/(p-1);
        quater1_0(u);
    }
}
void generate_5(){
    long long x01 = 1, x1 = 1, m1 = 16843, m = 2937, xi1, xi3;
    long long a = 113, c = 257, m2 =1027, x02 = 2, xi2;
    double u;
    for (int i = 0; i < loops; i++) {
        xi2 = (a * x02 + c) % m2;
        x02 = xi2;
        xi1 = (x01 + x1) % m1;
        x01 = x1;
        x1 = xi1;
        xi3 = abs(xi1 - xi2) % m;
        u = (double) xi3/(m-1);
        quater1_0(u);
    }
}

void generate_6(){
    long long m = 0, sigma = 1, a = 2, c= 119, x0 = 1, m1 = 16843, xi1;
    double xi2;

    for (int i = 0; i<loops; i++){
        double sum = 0;
        for (int j = 0; j<12; j++){
            xi1 = (a* x0 + c) % m1;
            x0 = xi1;
            sum += (double) xi1/(m1-1);
        }
        xi2 = sum - 6;
        quater3_3(xi2);
    }
}

void generate_7(){
    long long a = 11, c = 359, m = 16843, x0 = 1, a1=283, xi;
    long long x02 = 2, a2 = 561, c2=111, m2 = 2011, xi2;
    long long x03 = 3, a3 = 591, c3 = 123, m3 = 3057, xi3;
    double X1, X2, Y, S, u, v1, v2;
    double arr [loops];
    for (int i = 0; i < loops; i++) {
        xi = (a1 * x0 + c) % m;
        x0 = xi;
        arr[i] = (double) xi/(m-1);
    }
    for (int i = 0; i < (loops/2); i++){
        xi2 = (x02 * a2 +c2) % m2;
        x02 = xi2;
        xi3 = (x03 * a3 +c3) % m3;
        x03 = xi3;
        v1 = 2*arr[xi2]-1;
        v2 = 2*arr[xi3]-1;
        S = v1*v1+v2*v2;
        if (S>=1){
            i--;
        }
        else{
            X1 = v1*sqrt((-2*log(S))/S);
            X2 = v2*sqrt((-2*log(S))/S);
            quater3_3(X1);
            quater3_3(X2);
        }
    }
}
void generate_8() {
    long long a = 113, c = 257, m1 = 1027, x01 = 3, xi1;
    long long x02 = 1, x12 = 1, m2 = 1019, xi2;
    double u, v, X;
    for (int i = 0; i < loops; i++) {
        xi1 = (a * x01 + c) % m1;
        x01 = xi1;
        u = (double) xi1 / (m1 - 1);
        xi2 = (x02 + x12) % m2;
        x02 = x12;
        x12 = xi2;
        v = (double) xi2 / (m2 - 1);
        X = sqrt(8 / exp(1)) * ((v - 0.5) / u);
        if ((X * X <= (5 - 4 * exp(0.25) * u)) && (X * X < (4 * exp(-1.35) / u) + 1.4) && (X * X <= -4 * log(u))) {
            quater3_3(X);
        } else {
            i--;
        }
    }
}
    void generate_9(){
        long long a=243, c=359, m=16841, x0=1, xi;
        double X, u;
        for (int i = 0; i<loops; i++){
            xi = (a* x0 + c) % m;
            x0 = xi;
            u = (double) xi/(m-1);
            X = -40*log(u);
            if (X>=0){
                quater0_100(X);
            }
            else{
                i--;
            }
        }
    }
    void generate_10() {
        long long a = 11, c = 359, m = 16843, x0 = 1, a1=283, xi;
        long long x02 = 2, a2 = 561, c2=111, m2 = 2011, xi2;
        double X, Y, u, v;
        for (int i = 0; i < loops; i++) {
            xi = (a1 * x0 + c) % m;
            x0 = xi;
            u = (double) xi / (m - 1);
            Y= tan(3.14 * u);
            X= sqrt(2*a-1)*Y+a-1;
            if (X >= 0) {
                xi2 = (x02 * a2 +c2) % m2;
                x02 = xi2;
                v = (double) xi2 / (m2 - 1);
                if (v<=(1+Y*Y)*exp((a-1)*log(X/(a-1))-sqrt(2*a-1)*Y)) {
                    quater0_100(X);
                }
                else{
                    i--;
                }
            }
            else {
                i--;
            }
        }
    }
int main() {
    int a;
    double  n = 0;
    for (int i = 0; i < 10; i++){
        interval[i] = 0;
    }
    cin>> a;
    switch (a){
        case 1:{
            generate_1();
            for (int i = 0; i < 10; i++){
                cout<< (double) i/10 << " to " << (double) (i+1)/10 <<" "<< (double) interval[i]/loops<<endl;
                n += (double) interval[i]/loops;
            }
            break;
        }
        case 2:{
            generate_2();
            for (int i = 0; i < 10; i++){
                cout<< (double) i/10 << " to " << (double) (i+1)/10 <<" "<< (double) interval[i]/loops<<endl;
                n += (double) interval[i]/loops;
            }
            break;
        }
        case 3:{
            generate_3();
            for (int i = 0; i < 10; i++){
                cout<< (double) i/10 << " to " << (double) (i+1)/10 <<" "<< (double) interval[i]/loops<<endl;
                n += (double) interval[i]/loops;
            }
            break;
        }
        case 4:{
            generate_4();
            for (int i = 0; i < 10; i++){
                cout<< (double) i/10 << " to " << (double) (i+1)/10 <<" "<< (double) interval[i]/loops<<endl;
                n += (double) interval[i]/loops;
            }
            break;
        }
        case 5:{
            generate_5();
            for (int i = 0; i < 10; i++){
                cout<< (double) i/10 << " to " << (double) (i+1)/10 <<" "<< (double) interval[i]/loops<<endl;
                n += (double) interval[i]/loops;
            }
            break;
        }
        case 6:{
            generate_6();
            for (int i = -5; i < 5; i++){
                cout<< (double) i*0.6 << " to " << (double) (i+1)*0.6 <<" "<< (double) interval[i+5]/loops<<endl;
                n += (double) interval[i+5]/loops;
            }
            break;
        }
        case 7:{
            generate_7();
            for (int i = -5; i < 5; i++){
                cout<< (double) i*0.6 << " to " << (double) (i+1)*0.6 <<" "<< (double) interval[i+5]/loops<<endl;
                n += (double) interval[i+5]/loops;
            }
            break;
        }
        case 8:{
            generate_8();
            for (int i = -5; i < 5; i++){
                cout<< (double) i*0.6 << " to " << (double) (i+1)*0.6 <<" "<< (double) interval[i+5]/loops<<endl;
                n += (double) interval[i+5]/loops;
            }
            break;
        }
        case 9:{
            generate_9();
            for (int i = 0; i < 10; i++){
                cout<< (double) i*10 << " to " << (double) (i+1)*10 <<" "<< (double) interval[i]/loops<<endl;
                n += (double) interval[i]/loops;
            }
            break;
        }
        case 10:{
            generate_10();
            for (int i = 0; i < 10; i++){
                cout<< (double) i*10 << " to " << (double) (i+1)*10 <<" "<< (double) interval[i]/loops<<endl;
                n += (double) interval[i]/loops;
            }
            break;
        }
    }
    cout<< n;
    return 0;
}



