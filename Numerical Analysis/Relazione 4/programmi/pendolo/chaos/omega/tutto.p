set term postscript eps enhanced color solid rounded


set style data lines 
set xlabel "tempo [s]" 
set ylabel "theta [rad]" 
set pointsize 0.03


set output 'omega_+.eps'
plot  "omega_+",  2*pi notitle lt -0,4*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf omega_+.eps && rm omega_+.eps

set output 'omega_0.eps'
plot  "omega_0", 2*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf omega_0.eps && rm omega_0.eps

set output 'omega_-.eps'
plot  "omega_-", -2*pi notitle lt -0,  0 notitle lt -0 
set output
!epstopdf omega_-.eps && rm omega_-.eps



set output 'confrontoomega.eps'
set title "traiettoria di 3 pendoli con frequenza delle forzanti  variate di 0.0005 N  \n CASO CAOTICO" 
set notitle
plot "omega_+" ,"omega_0","omega_-", 2*pi notitle lt -0, 4*pi notitle lt -0,-2*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf confrontoomega.eps && rm confrontoomega.eps







