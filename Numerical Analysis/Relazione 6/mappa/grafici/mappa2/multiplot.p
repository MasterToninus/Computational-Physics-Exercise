set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro_1.eps'

set style data dots

set xlabel "parametro r"
set ylabel "Xn"
set notitle
set key left
unset tics


set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot


#  biforcazione 1
set size 0.5,0.5
set origin 0.0,0.5

x = 3 
y0 =0.63
y1 =0.69
set format x "%3.2g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[2.99:3.01][y0:y1]"prima_biforcazione" ls 3

#  terza biforcazione
set size 0.5,0.5
set origin 0.0,0.0

x = 3.5440875
y0 = 0.5150
y1 = 0.5325
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0 
set xtics (x)
plot[3.543:3.5455][y0:y1]"terza_biforcazione" ls 3

# seconda biforcazione
set size 0.5,0.5
set origin 0.5,0.5


x = 1 + sqrt(6)
y0 =0.438
y1 =0.442
set format x "%6.5g"
set arrow 1 from x,y1 to x,y0 
set xtics (x) 
plot[3.44947:3.44952][y0:y1]"seconda_biforcazione" ls 3

#
#  quarta biforcazione
set origin .5,0.


x = 3.564408
y0 =0.4850
y1 =0.4950
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.5642:3.56467][y0:y1]"quarta_biforcazione" ls 3

unset multiplot

set output
!epstopdf quadro_1.eps && rm quadro_1.eps

