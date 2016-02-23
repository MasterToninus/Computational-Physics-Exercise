reset

set term postscript eps enhanced color solid rounded

set style data lines
set xlabel "numero di iterazione n"
set ylabel "Resto"
set notitle
set point 0





set output 'confronto.eps'
plot[2000:6000] "sommatoria" lw 3, "sommatoria_rovescio" lw 3, 10e-6 lw 3
set output
!epstopdf confronto.eps && rm confronto.eps


