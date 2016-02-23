set term postscript eps enhanced color solid rounded


set style data lines 
set xlabel "tempo [s]" 
set ylabel "theta [rad]" 
set pointsize 0.01


set output 'F0_alta.eps'
plot "F0_alta_+", "F0_alta"  ,"F0_alta_-" ,  -2*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf F0_alta.eps && rm F0_alta.eps

set output 'F0_caos.eps'
plot  "F0_caos", 2*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf F0_caos.eps && rm F0_caos.eps

set output 'F0_bassa.eps'
plot  "F0_bassa_+","F0_bassa","F0_bassa_-",   0 notitle lt -0 
set output
!epstopdf F0_bassa.eps && rm F0_bassa.eps



set output 'confrontoF0.eps'
set notitle 
plot  "F0_alta"  ,"F0_caos","F0_bassa", 2*pi notitle lt -0,-2*pi notitle lt -0, 0 notitle lt -0
set output
!epstopdf confrontoF0.eps && rm confrontoF0.eps







