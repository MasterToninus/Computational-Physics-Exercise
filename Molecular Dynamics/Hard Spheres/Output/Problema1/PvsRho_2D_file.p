## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key left top

set xlabel "{/Symbol r}" font "Times-Italic,28" #offset 0,1.5
#set xrange [0.1:0.85]

set ylabel "<P/N>" font "Times-Italic,28" #offset 2.5,0 rotate by 0
#set yrange [0:1.01]
set trange [-0.01:1.01]

plot "PvsRho_2D.dat" using 1:2:3 title "N = 288" w yerrorbars  lt 1 lc 3 lw 2.2

set parametric
set trange [0:170]
const=0.4406868
#replot const,t lt 7 lw 1.7 lc 0 title "{/Symbol b}_{crit}"

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'PvsRho2D.eps'
replot
set output '|epstopdf  PvsRho2D.eps'

set term x11
set output
