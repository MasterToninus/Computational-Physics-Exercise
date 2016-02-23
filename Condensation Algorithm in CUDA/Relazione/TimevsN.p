

clear
reset

set key left top

set xlabel "Ordine della matrice"
set xrange [1:5000]

set ylabel "tempo [s]" rotate offset 1


plot "GpuTimeVsN_GTX480.dat" using ($1):($2/1000):($3/1000) title "Gpu" w yerrorbars lt 1 lc 3 lw 2.2
replot "GpuBestTimeVsN_GTX480.dat" using ($1):($2/1000):($3/1000) title "Gpu Best" w yerrorbars lt 1 lc 4 lw 2.2
replot "CpuTimeVsN.dat" using ($1):($2/1000):($3/1000) title "Cpu" w yerrorbars lt 1 lc 5 lw 2.2

replot "GpuTimeVsN_GTX480.dat" using ($1):($2/1000):($3/1000) notitle w lines lt 1 lc 3 
replot "GpuBestTimeVsN_GTX480.dat" using ($1):($2/1000):($3/1000) notitle w lines lt 1 lc 4 
replot "CpuTimeVsN.dat" using ($1):($2/1000):($3/1000) notitle w lines lt 1 lc 5 

set terminal postscript eps size 18cm,10cm enhanced color\
  font 'Helvetica,25'linewidth 1.5


set pointsize 1.45

set tmargin 1
set bmargin 3
set lmargin 8
set rmargin 3

set pointsize 1.45
set grid

set xtics nomirror

set output 'TimevsN.eps'
replot
set output '|epstopdf TimevsN.eps'


set term x11
set output
