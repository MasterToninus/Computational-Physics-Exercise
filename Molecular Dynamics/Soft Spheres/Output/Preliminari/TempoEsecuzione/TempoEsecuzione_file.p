

clear
reset



#	set title "Tempo Esecuzione vs L"
set key left top
set grid
unset border
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
set xtics nomirror
set ytics nomirror



set xlabel "N" font "Times-Italic,24" offset 0,0.5
#	set xrange [0:80]

set ylabel "t_{esec} (secondi)"  font "Times-Italic,24" offset 4,0
	set yrange [0: 0.00000000125]
	set ytics 0.00000000025

plot "T_esec_2D.dat" using 1:2 title "2D" w l	lt 1 lc 1 lw 3
replot "T_esec_3D.dat" using 1:2 title "3D" w l	lt 1 lc 2 lw 3



set terminal postscript eps size 18cm,8cm enhanced color \
    font 'Helvetica,25' linewidth 1.5
set output 'TempoEsecuzione_ConfrontoD.eps'

set tmargin 1
set bmargin 3
#set lmargin 4
set rmargin 1.2
replot
set output '|epstopdf TempoEsecuzione_ConfrontoD.eps'
set term x11
set output



