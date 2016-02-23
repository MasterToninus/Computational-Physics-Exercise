

clear
reset

set title "Confronto Tempi di Esecuzione vs Taglia della Matrice (zoom)"
set key left top

set xlabel "x"
set xrange [1:600]

set ylabel "t [s]"

plot "GpuTimeVsN_Zoom.dat" using ($1):($2/1000):($3/1000) title "Gpu" w yerrorbars lt 1 lc 3 lw 2.2
replot "GpuBestTimeVsN_Zoom.dat" using ($1):($2/1000):($3/1000) title "Gpu Best" w yerrorbars lt 1 lc 4 lw 2.2
replot "CpuTimeVsN_Zoom.dat" using ($1):($2/1000):($3/1000) title "Cpu" w yerrorbars lt 1 lc 5 lw 2.2

set terminal postscript eps size 18cm,10cm enhanced color\
  font 'Helvetica,25'linewidth 1.5


set pointsize 1.45

set tmargin 3
set bmargin 3
set lmargin 5
set rmargin 3

set pointsize 1.45
set grid

set xtics nomirror

set output 'TimevsN_Zoom.eps'
replot
set output '|epstopdf TimevsN_Zoom.eps'


set term x11
set output