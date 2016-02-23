
clear
reset

 set key center top

set style fill transparent pattern 4 noborder
unset border

set xlabel "O_{istantaneo}" font "Times-Italic,24" offset 0,0.5
#	set xrange [-3.5 : 1.5]

set ylabel " P( O_i )"  font "Times-Italic,24" offset 1.5,0 #rotate by 0
	set yrange [-0.5: 9.5]

plot 'IstoP.dat' title "P" w boxes lt 1 lc 1 lw 0.8
replot 'IstoT.dat' title "T" w boxes lt 1 lc 2 lw 0.8
replot 'IstoU.dat' title "U" w boxes lt 1 lc 3 lw 0.8

replot 'IstoP.dat' smooth csplines notitle  with l lt 1 lc 1 lw 1.8
replot 'IstoT.dat' smooth csplines notitle  with l lt 1 lc 2 lw 1.8
replot 'IstoU.dat' smooth csplines notitle  with l lt 1 lc 3 lw 1.8

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'IstoO.eps'
replot
set output '|epstopdf  IstoO.eps'

set term x11
set output

