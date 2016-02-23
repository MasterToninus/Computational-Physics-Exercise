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

plot './DistrodS_quad_bordo_0.dat' w boxes
replot './DistrodS_quad_bordo_1.dat' w boxes
replot './DistrodS_quad_bordo_2.dat' w boxes
replot './DistrodS_quad_bordo_3.dat' w boxes
replot './DistrodS_quad_bordo_4.dat' w boxes


L=1
d=2
Dmax =sqrt(d)*(0.5) 

set parametric
set trange [0:30]
const=Dmax
replot const,t lt 7 lw 1.7 lc 0 title "Distanza Max su toro"
replot 0.5,t lt 7 lw 1.7 lc 0 title "Distanza Max comportamento uniforme"
