

clear
reset

set title "Prova"
set key left top

set xlabel "x"
set xrange [1:5000]

set ylabel "t ms"

plot "GpuTimeVsN.dat" using 1:2:3 title "Gpu" w yerrorbars lt 1 lc 3 lw 2.2
replot "GpuBestTimeVsN.dat" using 1:2:3 title "Gpu Best" w yerrorbars lt 1 lc 4 lw 2.2
replot "CpuTimeVsN.dat" using 1:2:3 title "Cpu" w yerrorbars lt 1 lc 5 lw 2.2

set terminal postscript eps size 18cm,10cm enhanced color\
  font 'Helvetica,25'linewidth 1.5


set pointsize 1.45

set tmargin 3
set bmargin 3
set lmargin 15
set rmargin 3

set pointsize 1.45
set grid

set xtics nomirror

set output 'prova.eps'
replot
set output '|epstopdf prova.eps'


set term x11
set output
