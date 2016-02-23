## prototipo di grafico x y con barra di errore

clear
reset


set key left top

set xlabel "N" font "Times-Italic,24" offset 0,1.5
#set xrange [0.36:0.75]

set ylabel "<Z-1>" font "Times-Italic,24" offset 1.5,0 #rotate by 0
#set yrange [0:10]

plot[0:1050] "termPvsN_3D_ok.dat" using 1:2:3 notitle "<" w yerrorlines  lt 1 lc 1 lw 2.2

f1(x) = A + B/x		            # define the function to be fit
      A = 1; B = 1;            # initial guess for a1 and b1
fit f1(x) 'termPvsN_3D_ok.dat'  using 1:2 via A,B
replot f1(x) lw 1.5 lc 3 notitle




set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'termPvsN3D.eps'
replot
set output '|epstopdf  termPvsN3D.eps'

set term x11
set output
