clear
reset
set size ratio -1

L = 10.21
R = 2**(1/5)
set xtics L*2
set ytics L*2
unset border
unset label
unset key
unset clip
unset tics
epsilon = 0.05

set title "{/Symbol r} = 1.2   (configurazione iniziale BCC) "

set xrange [ 0 -epsilon: L+epsilon ] noreverse nowriteback
set yrange [ 0 : L ] noreverse nowriteback

plot 'Stato2D_Inizio_1.dat' u 1:2:3 w circles 
replot "Box2D.dat" u (L*($1)):(L*($2)):(L*($3)):(L*($4))  notitle  w vector nohead  lc 0 lt -1 lw 1 

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'SnapSolidoCompresso_Inizio_2D.eps'
replot
set output '|epstopdf  SnapSolidoCompresso_Inizio_2D.eps'

set term x11
set output


#############################################################################à


clear
reset
set size ratio -1

L = 22.36
R = 2**(1/5)
set xtics L*2
set ytics L*2
unset border
unset label
unset key
unset clip
unset tics
epsilon = 0.05

set title "{/Symbol r} = 0.25  (configurazione iniziale aggregata) "
set xrange [ 0 -epsilon: L+epsilon ] noreverse nowriteback
set yrange [ 0 : L ] noreverse nowriteback

plot 'Stato2D_Inizio_2.dat' u 1:2:3 w circles 
replot "Box2D.dat" u (L*($1)):(L*($2)):(L*($3)):(L*($4))  notitle  w vector nohead  lc 0 lt -1 lw 1 

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'SnapSolidoFreddo_Inizio_2D.eps'
replot
set output '|epstopdf  SnapSolidoFreddo_Inizio_2D.eps'

set term x11
set output

