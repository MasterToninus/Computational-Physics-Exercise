
clear
reset

set key left top

set xlabel "|dS|" font "Times-Italic,28" #offset 0,1.5
set xrange [0:3]

#set ylabel "p(x)" font "Times-Italic,28" offset 2.5,0 rotate by 0
set yrange [0:1.5]
set trange [-5:1]

set multiplot

f(x) = exp(-x**2*20)*x
d= 2
q = 2
B= -1/(d**(q/2)-1)
A= -(d**(q/2)/2**q)*A

g(x)= A*x**(-q) + B
plot x<=0.5 ? 2*x : g(x) 

replot f(x) 	title " Solido"   lt 1 lc 3 lw 2.2

set parametric
set trange [0:170]
const=sqrt(d)/2
plot const,t lt 7 lw 1.7 lc 0 title "{/Symbol b}_{crit}"

