#include<stdio.h>
#include<time.h>


int main() {
system("echo 0 > /sys/class/gpio/gpio17/value");
sleep(1);
system("echo 1 > /sys/class/gpio/gpio17/value");
return 0;
}


 
