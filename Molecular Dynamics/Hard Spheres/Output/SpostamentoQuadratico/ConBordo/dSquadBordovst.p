## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
#set key left top

#set xlabel "{/Symbol r}" font "Times-Italic,28" #offset 0,1.5
#set xrange [0.1:0.85]

#set ylabel "<P/N>" font "Times-Italic,28" #offset 2.5,0 rotate by 0
#set yrange [0:1.01]
set trange [-0.01:1.01]

	plot "DistrodS_quad_bordo_0.dat" using 1:2 notitle w l  lt 1 lc 1 lw 2.2
#	plot "DistrodS_quad_bordo_0.dat" using 1:2:3 title "eta = " w yerrorbars  lt 1 lc 1 lw 2.2


#	replot "DistrodS_quad_bordo_1.dat" using 1:2:3 title "eta = " w yerrorbars  lt 1 lc 2 lw 2.2
	replot "DistrodS_quad_bordo_1.dat" using 1:2 notitle "eta = " w l  lt 1 lc 2 lw 2.2


#	replot "DistrodS_quad_bordo_2.dat" using 1:2:3 title "eta = " w yerrorbars  lt 1 lc 3 lw 2.2
	replot "DistrodS_quad_bordo_2.dat" using 1:2 notitle "eta = " w l  lt 1 lc 3 lw 2.2

#	replot "DistrodS_quad_bordo_3.dat" using 1:2:3 title "eta = " w yerrorbars  lt 1 lc 4 lw 2.2
	replot "DistrodS_quad_bordo_3.dat" using 1:2 notitle "eta = " w l  lt 1 lc 4 lw 2.2

#replot "DistrodS_quad_bordo_4.dat" using 1:2:3 title "eta = " w yerrorbars  lt 1 lc 5 lw 2.2

L=1
d=2
Dmax =sqrt(d)*(0.5) 

replot Dmax
