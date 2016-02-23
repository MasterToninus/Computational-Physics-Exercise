
clear
reset

set style fill transparent pattern 4 noborder
unset border



plot    'IstoVx_eta0.dat' title '{/Symbol h} = 0.615' with boxes lt 1 lc 1 lw 0.8
replot	'IstoVx_eta1.dat' title '{/Symbol h} = 0.515' with boxes lt 1 lc 2 lw 0.8
replot	'IstoVx_eta2.dat' title '{/Symbol h} = 0.415' with boxes lt 1 lc 3 lw 0.8


replot    'IstoVx_eta0.dat' smooth csplines notitle '{/Symbol h} = 0.75' with l lt 1 lc 1 lw 1.8
replot    'IstoVx_eta1.dat' smooth csplines notitle '{/Symbol h} = 0.67' with l lt 1 lc 2 lw 1.8
replot    'IstoVx_eta2.dat' smooth csplines notitle '{/Symbol h} = 0.58' with l lt 1 lc 3 lw 1.8

f(x) = exp(-0.5*x**2)/sqrt(pi*2) 
replot f(x) title 'Distribuzione attesa' lt 1 lc 0 lw 1.8


set xlabel "v_x" font "Times-Italic,24" offset 0,0.5
set xrange [-4:4]

set ylabel "P( v_x )" font "Times-Italic,24" offset 1.5,0 #rotate by 0




set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'DistroVx.eps'
replot
set output '|epstopdf  DistroVx.eps'

set term x11
set output

