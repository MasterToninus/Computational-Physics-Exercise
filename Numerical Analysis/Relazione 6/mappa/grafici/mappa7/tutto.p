set term postscript eps enhanced color solid rounded

set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle
set key left



 
set output 'mappa_logistica.eps'
plot "mappa_logistica"
set output
!epstopdf mappa_logistica.eps && rm mappa_logistica.eps

