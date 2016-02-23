## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key left top

set xlabel "Tempo evoluzione [t]" font "Times-Italic,24" #offset 0,1.5
#set xrange [0:1]
set xtics 0.25


set ylabel "<dS^2> [L]" font "Times-Italic,24" offset 1.5,0 
set yrange [-0.0025:0.02]
set trange [-0.01:1.01]

plot "dS_quad_vsDt_eta0.dat" using 1:2:3 title "{/Symbol h} = 0.680"  w l  lt 1 lc 1 lw 2.2 #	w yerrorbars
replot "dS_quad_vsDt_eta1.dat" using 1:2:3 title "{/Symbol h} = 0.508"  w l  lt 1 lc 2 lw 2.2  #	 w yerrorbars
replot "dS_quad_vsDt_eta2.dat" using 1:2:3 title "{/Symbol h} = 0.337"  w l  lt 1 lc 3 lw 2.2  #	 w yerrorbars
replot "dS_quad_vsDt_eta3.dat" using 1:2:3 title "{/Symbol h} = 0.165"  w l  lt 1 lc 4 lw 2.2



set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'dSquadvsDt_3D.eps'
replot
set output '|epstopdf  dSquadvsDt_3D.eps'

set term x11
set output
