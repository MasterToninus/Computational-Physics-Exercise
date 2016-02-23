clear
reset

set xlabel "U*/N istantaneo"
#	set xrange [0: 0.9]

set ylabel " distro di probabilità"
#	set yrange [-0.02:2.5]

set style fill transparent pattern 10 bo border -1


plot 'IstoU_N108.dat' title "U_is N = 108" w boxes  lc 1

replot 'IstoU_N500.dat' title "U_is N = 500" w boxes lc 2

set parametric
set trange [0:12]
UmedioN108 = -3.49772
UmedioN500 = -3.48813
	replot UmedioN108,t title "Umedio N108" lt -2 lc 1
	replot UmedioN500,t title "Umedio N500" lt -2 lc 2

