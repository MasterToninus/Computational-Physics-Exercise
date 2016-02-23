

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



set xlabel "N" offset 0,0.5
#set xrange [0:80]

set ylabel "t_{esec} (secondi)" offset 1.5,0
#set yrange [0:0.09]
#set ytics 0.02

plot "T_esec_vsN3D.dat" using 1:2 title "3D"	lw 3 lc 1
replot "T_esec_vsN3D.dat" using 1:2 notitle "3D" w l lw 3 lc 1
replot "T_esec_vsN2D.dat" using 1:2 title "2D"	lw 3	lc 3

f1(x) = a1*(x**b1)            # define the function to be fit
      a1 = 1; b1 = 2;            # initial guess for a1 and b1
fit f1(x) 'T_esec_vsN2D.dat'  using 1:2 via a1, b1 
replot f1(x) lw 1.5 lc 3 notitle


set terminal postscript eps size 18cm,8cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'T_esec.eps'
replot
set output '|epstopdf  T_esec.eps'

set term x11
set output
