set term postscript eps enhanced color solid rounded
set output 'caos.eps'

set title "traiettoria di 3 pendoli con diverse forzanti" 
set style data lines 
set xlabel "tempo [s]" 
set ylabel "theta [rad]" 
set pointsize 0.01

plot[0:100]  "3_theta_t" ,"2_theta_t","1_theta_t",2*pi notitle lt -0, -2*pi notitle lt -0, -4*pi notitle lt -0, 0 notitle lt -0

set output

!epstopdf caos.eps && rm caos.eps





