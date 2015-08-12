Fs = 44100;
N = 64105;
Ft = 697;

dur = N/Fs;
tt = 0 : (1/Fs) : dur-1/Fs;
input =  1*sin(2*pi*697*tt) +  2*sin(2*pi*1200*tt); 

k = round((N*Ft)/Fs);

omega = 2*pi*k/N;
sine = sin(omega);
cosine = 2*cos(omega);

q0 = 0;
q1 = 0;
q2 = 1;
n = 1;

while (n < N + 1)
	q0 = cosine * q1 - q2 + input(n);
	q2 = q1;
	q1 = q0;
	n = n + 1;
end
power = q2 *q2 + q1 * q1 - cosine * q1 *q2

#waitforbuttonpress;
