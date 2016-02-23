
clear
reset

set style fill transparent pattern 4 noborder
unset border

set xlabel "U^*/N _{istantaneo}" font "Times-Italic,24" offset 0,0.5
	set xrange [-3.8 : -3.2]

set ylabel " P( U_i^*/N )"  font "Times-Italic,24" offset 1.5,0 #rotate by 0
	set yrange [-0.5: 12]



plot 'IstoU_N108.dat' title "U_is N = 108" with boxes lt 1 lc 1 lw 0.8
replot 'IstoU_N500.dat' title "U_is N = 500" with boxes lt 1 lc 2 lw 0.8

replot 'IstoU_N108.dat' smooth csplines notitle '{/Symbol h} = 0.75' with l lt 1 lc 1 lw 1.8
replot 'IstoU_N500.dat' smooth csplines notitle '{/Symbol h} = 0.67' with l lt 1 lc 2 lw 1.8



set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'IstoU.eps'
replot
set output '|epstopdf  IstoU.eps'

set term x11
set output

