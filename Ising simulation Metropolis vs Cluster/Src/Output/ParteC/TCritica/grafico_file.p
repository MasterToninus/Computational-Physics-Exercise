clear
reset

#set title "<S_0 S_t> vs t (Cluster)"
set style data dots
set bars large
set key top left

plot "grafpo.dat" using 1:2:3 title "{/Symbol x}_L({/Symbol b}_c)" w yerrorbars 		 lw 3 lc 1 
A=1
B=1
C=1
f(x)= A*x
	fit f(x) "grafpo.dat"  using 1:2:3 via A
	replot f(x) title "{/Symbol x}_L({/Symbol b}_c) = L" 															 lw 1 lt 1 lc 0		

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.25
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
unset border

#set log x
set xlabel " L" font "Times-Italic,22" offset 1,0
#	set xrange [0:100]
#	set xtics 20
set mxtic 2

set ylabel "{/Symbol x}_L({/Symbol b}_c)" font "Times-Italic,22" offset 0,1 rotate by 90
	set yrange [0:350]
#	set ytics 0.2
set mytic 2

set xtics nomirror
set ytics nomirror

set output 'grafpo_Tc.eps'
replot
set output '|epstopdf  grafpo_Tc.eps'

set term x11
set output
  
