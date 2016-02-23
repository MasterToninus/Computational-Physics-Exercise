##Stampo lo stato inziale le particelle come cerchietti e sovrappongo le velocità

clear
reset
set size ratio -1
	L = 18.8982
	set xrange [0:L]
	set yrange [0:L]
plot 'motoP5.dat' u 1:2 lt 3 w l
#	replot 'motoP5.dat' using 1:2:3:4 with vectors head filled lt 1

replot 0 notitle lc 0
replot L notitle lc 0
set parametric

set trange[0:L]
replot 0,t notitle lc 0
replot L,t notitle lc 0

