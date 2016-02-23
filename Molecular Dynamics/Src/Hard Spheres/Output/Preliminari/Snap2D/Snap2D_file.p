clear
reset
set size ratio -1

L = 1
set xtics L
set ytics L
unset border
unset tics
unset key

set title "{/Symbol h} = 0.76"
plot[-0.1:1.1][-0.1:1.1] 'Stato_eta0.dat' u 1:2:3  w circles
#replot 'Stato_eta0.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot "Box2D.dat" u (L*($1)):(L*($2)):(L*($3)):(L*($4))  notitle  w vector nohead  lc 0 lt -1 lw 1 

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'SnapSolido_2D.eps'
replot
set output '|epstopdf  SnapSolido_2D.eps'

set term x11
set output





clear
reset
set size ratio -1

L = 1
set xtics L
set ytics L
unset border
unset tics
unset key

set title "{/Symbol h} = 0.69"
plot[-0.1:1.1][-0.1:1.1] 'Stato_eta1.dat' u 1:2:3  w circles
#replot 'Stato_eta1.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot "Box2D.dat" u (L*($1)):(L*($2)):(L*($3)):(L*($4))  notitle  w vector nohead  lc 0 lt -1 lw 1 

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'SnapMeta_2D.eps'
replot
set output '|epstopdf  SnapMeta_2D.eps'

set term x11
set output




clear
reset
set size ratio -1

L = 1
set xtics L
set ytics L
unset border
unset tics
unset key

set title "{/Symbol h} = 0.62"
plot[-0.1:1.1][-0.1:1.1] 'Stato_eta2.dat' u 1:2:3  w circles
#replot 'Stato_eta2.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot "Box2D.dat" u (L*($1)):(L*($2)):(L*($3)):(L*($4))  notitle  w vector nohead  lc 0 lt -1 lw 1 

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'SnapLiquido_2D.eps'
replot
set output '|epstopdf  SnapLiquido_2D.eps'

set term x11
set output



clear
reset
set size ratio -1

L = 1
set xtics L
set ytics L
unset border
unset tics
unset key

set title "Stato iniziale {/Symbol h} = 0.76"
plot[-0.1:1.1][-0.1:1.1] 'Stato_inizio.dat' u 1:2:3  w circles
#replot 'Stato_inizio.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot "Box2D.dat" u (L*($1)):(L*($2)):(L*($3)):(L*($4))  notitle  w vector nohead  lc 0 lt -1 lw 1 

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'SnapInizio_2D.eps'
replot
set output '|epstopdf  SnapInizio_2D.eps'

set term x11
set output
