set term postscript eps enhanced color solid rounded


set style data lines 
set xlabel "tempo [s]" 
set ylabel "theta [rad]" 
set pointsize 0.01


set output 'theta_+.eps'
plot  "theta_+",2*pi notitle lt -0,-2*pi notitle lt -0, -4*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf theta_+.eps && rm theta_+.eps

set output 'theta_-.eps'
plot  "theta_-" ,2*pi notitle lt -0, 4*pi notitle lt -0, 0 notitle lt -0 
set output
!epstopdf theta_-.eps && rm theta_-.eps

set output 'theta_0.eps'
plot  "theta_0",2*pi notitle lt -0,-2*pi notitle lt -0, -4*pi notitle lt -0, 0 notitle lt -0 
set output
!epstopdf theta_0.eps && rm theta_0.eps

set output 'confrontotheta.eps'
set title "3 traittorie con angolo iniziale variato di 0.005 rad \n CASO CAOTICO" 
set notitle
plot "theta_+" ,"theta_0","theta_-",2*pi notitle lt -0,4*pi notitle lt -0, -2*pi notitle lt -0, -4*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf confrontotheta.eps && rm confrontotheta.eps







