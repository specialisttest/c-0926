#ifndef _MY_H_
#define _MY_H_

void say_hello();
void say_hello_w_name(const char* name);
void say_hello_w_name_age(const char* name, int age);

//double my_average(int a, int b);
double my_average(int, int);

double average_m(int m_size, int* m);
double average_n(int n, ...);

#endif
