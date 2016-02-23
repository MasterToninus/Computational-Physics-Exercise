set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'superquadro.eps'

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
set size 0.33333,0.25
set origin 0.0,0.75

x = 3 
y0 =0.63
y1 =0.69
set format x "%3.2g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[2.99:3.01][y0:y1]"prima_biforcazione" ls 3

# seconda biforcazione
set size 0.33333,0.25
set origin 0.33333,0.75


x = 1 + sqrt(6)
y0 =0.438
y1 =0.442
set format x "%6.5g"
set arrow 1 from x,y1 to x,y0 
set xtics (x) 
plot[3.44947:3.44952][y0:y1]"seconda_biforcazione" ls 3


#
#  terza biforcazione
set size 0.33333,0.25
set origin 0.66666,0.75

x = 3.5440875
y0 = 0.5150
y1 = 0.5325
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0 
set xtics (x)
plot[3.543:3.5455][y0:y1]"terza_biforcazione" ls 3


#
#  quarta biforcazione
set size 0.33333,0.25
set origin 0.0,0.50

x = 3.564408
y0 =0.4850
y1 =0.4950
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.5642:3.56467][y0:y1]"quarta_biforcazione" ls 3



#  quinta biforcazione
set size 0.33333,0.25
set origin 0.33333,0.50

x = 3.568758
y0 = 0.498
y1 = 0.509
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.5682:3.5695][y0:y1]"quinta_biforcazione" ls 3


# sesta biforcazione
set size 0.33333,0.25
set origin 0.66666,0.50


x = 3.5696916
y0 = 0.4980
y1 = 0.4990
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56968:3.56970][y0:y1]"sesta_biforcazione" ls 3


#  settima biforcazione
set size 0.33333,0.25
set origin 0.0,0.25

x = 3.56989127
y0 = 0.5001
y1 = 0.5011
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56988:3.5699][y0:y1]"settima_biforcazione" ls 3







#
#  ottava biforcazione
set size 0.33333,0.25
set origin 0.33333,0.25

x = 3.5699340125
y0 = 0.4996
y1 = 0.4999
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56993000:3.56993800][y0:y1]"ottava_biforcazione" ls 3


#  nona biforcazione
set size 0.33333,0.25
set origin 0.66666,0.25

x = 3.56994318
y0 = 0.333339
y1 = 0.37
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0
set xtics (x)
plot[3.5699420:3.569945][y0:y1]"nona_biforcazione" ls 3

# decima biforcazione
set size 0.33333,0.25
set origin 0.0,0.0

set format x "%10.9g"
x = 3.569945139
y0 = 0.3333392
y1 = 0.3333395
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.569945:3.5699455][y0:y1]"decima_biforcazione" ls 3

#  undicesima biforcazione

set origin 0.33333,0.0

x = 3.5699455575
y0 = 0.333339404
y1 = 0.333339425
set arrow 1 from x,y1 to x,y0  
y = 3.5699456475
set arrow 2 from y,y1 to y,y0 
set format x "%12.11g"
set xtics (x,y)
plot[3.5699455:3.5699457][y0:y1]"undicesima_biforcazione" ls 3






unset multiplot


set output
!epstopdf superquadro.eps && rm superquadro.eps

