## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key left top

set xlabel "{/Symbol r}" font "Times-Italic,28" #offset 0,1.5
#set xrange [0.1:0.85]

set ylabel "<Tc>" font "Times-Italic,28" #offset 2.5,0 rotate by 0
#set yrange [0:1.01]
set trange [-0.01:1.01]

plot "TcvsRho_2D.dat"  title "N = 288"   lt 1 lc 3 lw 2.2


set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'Tcvsrho2D.eps'
replot
set output '|epstopdf  Tcvsrho2D.eps'

set term x11
set output
