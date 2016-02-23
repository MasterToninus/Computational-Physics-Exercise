set term postscript eps enhanced color solid rounded


set pointsize 0.00001
set xlabel "parametro r"
set ylabel "Xn"
set notitle
unset key
unset tics


set output 'prima_biforcazione.eps'
x = 3 
y0 =0.63
y1 =0.69
set format x "%3.2g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[2.99:3.01][y0:y1]"prima_biforcazione" ls 3
set output
!epstopdf prima_biforcazione.eps && rm prima_biforcazione.eps

set output 'seconda_biforcazione.eps'
x = 1 + sqrt(6)
y0 =0.438
y1 =0.442
set format x "%6.5g"
set arrow 1 from x,y1 to x,y0 
set xtics (x) 
plot[3.44947:3.44952][y0:y1]"seconda_biforcazione" ls 3
set output
!epstopdf seconda_biforcazione.eps && rm seconda_biforcazione.eps


set output 'terza_biforcazione.eps'
x = 3.5440875
y0 = 0.5150
y1 = 0.5325
set format x "%9.8g"
set arrow 1 from x,0 to x,1 
set xtics (x)
plot[3.543:3.5455][y0:y1]"terza_biforcazione" ls 3
set output
!epstopdf terza_biforcazione.eps && rm terza_biforcazione.eps

set output 'quarta_biforcazione.eps'
x = 3.564408
y0 =0.4850
y1 =0.4950
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.5642:3.56467][y0:y1]"quarta_biforcazione" ls 3
set output
!epstopdf quarta_biforcazione.eps && rm quarta_biforcazione.eps

set output 'quinta_biforcazione.eps'
x = 3.568758
y0 = 0.498
y1 = 0.509
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.5682:3.5695][y0:y1]"quinta_biforcazione" ls 3
set output
!epstopdf quinta_biforcazione.eps && rm quinta_biforcazione.eps

set output 'sesta_biforcazione.eps'
x = 3.5696916
y0 = 0.4980
y1 = 0.4990
set format x "%9.8g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56968:3.56970][y0:y1]"sesta_biforcazione" ls 3
set output
!epstopdf sesta_biforcazione.eps && rm sesta_biforcazione.eps

set output 'settima_biforcazione.eps'
x = 3.56989127
y0 = 0.5001
y1 = 0.5011
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56988:3.5699][y0:y1]"settima_biforcazione" ls 3
set output
!epstopdf settima_biforcazione.eps && rm settima_biforcazione.eps

set output 'ottava_biforcazione.eps'
x = 3.5699340125
y0 = 0.4996
y1 = 0.4999
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56993000:3.56993800][y0:y1]"ottava_biforcazione" ls 3
set output
!epstopdf ottava_biforcazione.eps && rm ottava_biforcazione.eps

set output 'nona_biforcazione.eps'
x = 3.56994318
y0 = 0.369
y1 = 0.37
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0
set xtics (x)
plot[3.5699420:3.569945][y0:y1]"nona_biforcazione" ls 3
set output
!epstopdf nona_biforcazione.eps && rm nona_biforcazione.eps

set output 'decima_biforcazione.eps'
set format x "%10.9g"
x = 3.569945139
y0 = 0.3692
y1 = 0.3695
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.569945:3.5699455][y0:y1]"decima_biforcazione" ls 3
set output
!epstopdf decima_biforcazione.eps && rm decima_biforcazione.eps


set output 'undicesima_biforcazione.eps'
x = 3.5699455575
y0 = 0.369404
y1 = 0.369425
set arrow 1 from x,y1 to x,y0  
y = 3.5699456475
set arrow 2 from y,y1 to y,y0 
set format x "%12.11g"
set xtics (x,y)
plot[3.5699455:3.5699457][y0:y1]"undicesima_biforcazione" ls 3
set output
!epstopdf undicesima_biforcazione.eps && rm undicesima_biforcazione.eps










