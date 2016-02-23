set term postscript eps enhanced color solid rounded


set pointsize 0.00001
set xlabel "parametro r"
set ylabel "Xn"
set notitle
unset key
unset tics


set output 'seconda_biforcazione.eps'
x = 1 + sqrt(6)
y0 =0.438
y1 =0.442
set format x "%6.5g"
set arrow 1 from x,y1 to x,y0 
set xtics (x) 
plot[3.44947:3.44952][y0:y1]"seconda_biforcazione" ls 3
set output
!epstopdf seconda_biforcazione.eps && rm seconda_biforcazione.eps


