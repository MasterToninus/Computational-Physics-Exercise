set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro_3.eps'

set style data dots

set xlabel "parametro r"
set ylabel "Xn"
set notitle
set key left
unset tics


set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot


#  nona biforcazione
set size 0.5,0.5
set origin 0.0,0.5

x = 3.56994318
y0 = 0.369
y1 = 0.37
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0
set xtics (x)
plot[3.5699420:3.569945][y0:y1]"nona_biforcazione" ls 3

#  undicesima biforcazione
set size 1,0.5
set origin 0.0,0.0

x = 3.5699455575
y0 = 0.369404
y1 = 0.369425
set arrow 1 from x,y1 to x,y0  
y = 3.5699456475
set arrow 2 from y,y1 to y,y0 
set format x "%12.11g"
set xtics (x,y)
plot[3.5699455:3.5699457][y0:y1]"undicesima_biforcazione" ls 3


# decima biforcazione
set size 0.5,0.5
set origin 0.5,0.5

set format x "%10.9g"
x = 3.569945139
y0 = 0.3692
y1 = 0.3695
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.569945:3.5699455][y0:y1]"decima_biforcazione" ls 3

#

unset multiplot

set output
!epstopdf quadro_3.eps && rm quadro_3.eps

