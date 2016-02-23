clear
reset

set xlabel "U*/N istantaneo"
	set xrange [-0.9: 0.9]

set ylabel " distro di probabilità"
#	set yrange [-0.02:2.5]

set style fill transparent pattern 10 bo border -1


plot 'IstoP_N100.dat' title "P_is N = 100" w boxes  

replot 'IstoP_N150.dat' title "P_is N = 150" w boxes 

replot 'IstoP_N250.dat' title "P_is N = 250" w boxes 

replot 'IstoP_N500.dat' title "P_is N = 500" w boxes 

replot 'IstoP_N800.dat' title "P_is N = 800" w boxes 

replot 'IstoP_N1000.dat' title "P_is N = 1000" w boxes 


