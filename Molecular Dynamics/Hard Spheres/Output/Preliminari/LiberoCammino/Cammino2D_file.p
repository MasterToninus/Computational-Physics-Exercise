
clear
reset
set size ratio -1

L = 1
set xtics 0.25
set ytics 0.25
unset border

set grid

plot 'Moto_P2D_Eta0.dat' w lines title "{/Symbol h} = 0.72" lt -1 lc 1
replot 'Moto_P2D_Eta1.dat' w lines title "{/Symbol h} = 0.54" lt -1  lc 2
replot 'Moto_P2D_Eta2.dat' w lines title "{/Symbol h} = 0.36" lt -1  lc 3
replot 'Moto_P2D_Eta3.dat' w lines title "{/Symbol h} = 0.18" lt -1  lc 4
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)) notitle  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Lc_2D.eps'
replot
set output '|epstopdf  Lc_2D.eps'

set term x11
set output

