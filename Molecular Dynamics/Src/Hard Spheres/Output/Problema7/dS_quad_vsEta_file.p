## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key right top

set xlabel "{/Symbol h}" font "Times-Italic,28" #offset 0,1.5
#set xrange [0.1:0.85]

set ylabel "<dS^2>( 0.5[t]) [L]" font "Times-Italic,28" #offset 2.5,0 rotate by 0
#set yrange [0:1.01]
set trange [-0.01:1.01]

plot "dS_quad_vsEta.dat" using 1:2:3 title "N = 450" 	w yerrorbars  lt 1 lc 1 lw 0.8
replot "dS_quad_vsEta.dat" using 1:2:3 notitle "{/Symbol h} = 0.785" 	w l  lt 1 lc 1 lw 2.2



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

set output 'dSquadvsEta_3D.eps'
replot
set output '|epstopdf  dSquadvsEta_3D.eps'

set term x11
set output
