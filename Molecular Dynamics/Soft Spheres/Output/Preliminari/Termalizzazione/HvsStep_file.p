
clear
reset


plot 'HmediovsStepTD_rho0.dat'  title "{/Symbol r} = 0.6" w line lt 1 lc 1 lw 2.2
replot 'HmediovsStepTD_rho1.dat' title "{/Symbol r} = 0.9" w line lt 1 lc 2 lw 2.2
replot 'HmediovsStepTD_rho2.dat' title "{/Symbol r} = 1.2" w line lt 1 lc 3 lw 2.2


replot - sqrt(pi/2) title "H_{Boltzman} atteso" lc 0 lw 1.8

 set key right top
unset border


set xlabel "# Step evoluzione" font "Times-Italic,24" offset 0,0.5
	set xrange [0:2500]

set ylabel "H_{Boltzman}" font "Times-Italic,24" offset 1.5#,0
#	set yrange [0: 0.00000000125]
#	set ytics 0.00000000025

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'HvsStep.eps'
replot
set output '|epstopdf  HvsStep.eps'

set term x11
set output
