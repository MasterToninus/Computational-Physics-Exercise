## prototipo di grafico x y con barra di errore

clear
reset

#set title "C vs beta (valore ottenuto con 1500 campioni per punto)"
set key left top

set xlabel "{/Symbol b}" font "Times-Italic,28"
	set xrange [0.1: 0.85]

set ylabel "c" offset 2.5,0 font "Times-Italic,28" rotate by 0
	set yrange [0:2.5]

plot "cvsBeta_N100.dat" using 1:2:3 title "L = 100" w yerrorbars lt 1 lc 3 lw 2.2
replot "cvsBeta_N100.dat" using 1:2 notitle with lines 			 lt 1 lc 3 lw 2.2

set parametric
set trange [0:170]
const=0.4406868
replot const,t lt 7 lw 1.7 lc 0 title "{/Symbol b}_{crit}"

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror


set output 'cvsBeta.eps'
replot
set output '|epstopdf  cvsBeta.eps'

set term x11
set output
  
  