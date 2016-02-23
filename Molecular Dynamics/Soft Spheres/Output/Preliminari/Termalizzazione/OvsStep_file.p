
clear
reset


#	plot 'PvsStep_Rho0.dat' title "Z ({/Symbol r} = 0.6)" w l lt 1 lc 1
#	replot 'PvsStep_Rho1.dat' title "Z ({/Symbol r} = 0.9)" w l lt 1 lc 2
#	replot 'PvsStep_Rho2.dat' title "Z ({/Symbol r} = 1.2)" w l lt 1 lc 3

plot 'UvsStep_Rho0.dat' title "U ({/Symbol r} = 0.6)" w l lt 2 lc 1
replot 'UvsStep_Rho1.dat' title "U ({/Symbol r} = 0.9)" w l lt 2 lc 2
replot 'UvsStep_Rho2.dat' title "U ({/Symbol r} = 1.2)"  w l lt 2 lc 3

replot 'TvsStep_Rho0.dat' title "kT ({/Symbol r} = 0.6)" w l lt 1 lc 1
replot 'TvsStep_Rho1.dat' title "kT ({/Symbol r} = 0.9)" w lines lt 1 lc 2
replot 'TvsStep_Rho2.dat' title "kT ({/Symbol r} = 1.2)" w lines lt 1 lc 3


 set key right top
unset border


set xlabel "# Step evoluzione" font "Times-Italic,24" offset 0,0.5
	set xrange [0:2500]

set ylabel "O_{istantaneo}" font "Times-Italic,24" offset 1.5#,0
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

set output 'OvsStep.eps'
replot
set output '|epstopdf  OvsStep.eps'

set term x11
set output








clear
reset


plot 'PvsStep_Rho0.dat' title "Z-1 ({/Symbol r} = 0.6)" w l lt 1 lc 1
replot 'PvsStep_Rho1.dat' title "Z-1 ({/Symbol r} = 0.9)" w l lt 1 lc 2
replot 'PvsStep_Rho2.dat' title "Z-1 ({/Symbol r} = 1.2)" w l lt 1 lc 3



 set key right bottom
unset border


set xlabel "# Step evoluzione" font "Times-Italic,24" offset 0,0.5
	set xrange [0:2500]

set ylabel "P^{*}_{i}" font "Times-Italic,24" offset 1.5#,0
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

set output 'PvsStep.eps'
replot
set output '|epstopdf  PvsStep.eps'

set term x11
set output





