set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro_2.eps'

set style data dots

set xlabel "parametro r"
set ylabel "Xn"
set notitle
set key left
unset tics


set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot


#  quinta biforcazione
set size 0.5,0.5
set origin 0.0,0.5

x = 3.568758
y0 = 0.498
y1 = 0.509
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.5682:3.5695][y0:y1]"quinta_biforcazione" ls 3

#  settima biforcazione
set size 0.5,0.5
set origin 0.0,0.0

x = 3.56989127
y0 = 0.5001
y1 = 0.5011
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56988:3.5699][y0:y1]"settima_biforcazione" ls 3

# sesta biforcazione
set size 0.5,0.5
set origin 0.5,0.5


x = 3.5696916
y0 = 0.4980
y1 = 0.4990
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56968:3.56970][y0:y1]"sesta_biforcazione" ls 3

#
#  ottava biforcazione
set origin .5,0.


x = 3.5699340125
y0 = 0.4996
y1 = 0.4999
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56993000:3.56993800][y0:y1]"ottava_biforcazione" ls 3

unset multiplot

set output
!epstopdf quadro_2.eps && rm quadro_2.eps

