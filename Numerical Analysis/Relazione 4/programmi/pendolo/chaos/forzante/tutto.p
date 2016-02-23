set term postscript eps enhanced color solid rounded


set style data lines 
set xlabel "tempo [s]" 
set ylabel "F0 [rad]" 
set pointsize 0.01


set output 'F0_+.eps'
plot  "F0_+",-2*pi notitle lt -0,-4*pi notitle lt -0,-6*pi notitle lt -0,-8*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf F0_+.eps && rm F0_+.eps

set output 'F0_-.eps'
plot  "F0_-", -2*pi notitle lt -0, 0 notitle lt -0 
set output
!epstopdf F0_-.eps && rm F0_-.eps

set output 'F0_0.eps'
plot  "F0_0", 2*pi notitle lt -0, 0 notitle lt -0 
set output
!epstopdf F0_0.eps && rm F0_0.eps

set output 'confrontoF0.eps'
set title "traiettoria di 3 pendoli con forzanti  variate di 0.0005 N \n CASO CAOTICO" 
set notitle 
plot "F0_+" ,"F0_0","F0_-", -2*pi notitle lt -0, 2*pi notitle lt -0,-4*pi notitle lt -0,-6*pi notitle lt -0,-8*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf confrontoF0.eps && rm confrontoF0.eps







