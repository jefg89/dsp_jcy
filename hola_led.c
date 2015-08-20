#include<stdio.h>
#include<time.h>


int main() {

system("echo 17 > /sys/class/gpio/export");
system("echo out > /sys/class/gpio/gpio17/direction");
system("echo 0 > /sys/class/gpio/gpio17/value");
sleep(1);
system("echo 1 > /sys/class/gpio/gpio17/value");
system("echo 17 > /sys/class/gpio/unexport");
return 0;
}


 
