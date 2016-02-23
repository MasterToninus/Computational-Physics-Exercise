
clear
reset
set size ratio -1

L = 1
set xtics L
set ytics L
unset border
unset tics
unset key

set title "{/Symbol h} = 0.72"
plot 'Eta0_2D_Fine.dat' u 1:2:3  w circles
replot 'Eta0_2D_Spostamento.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot 'Eta0_2D_Spostamento.dat' u 1:2 pt 7 ps 0.5
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4))   w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta0_2D.eps'
replot
set output '|epstopdf  Eta0_2D.eps'

set term x11
set output

set title "{/Symbol h} = 0.62"
plot 'Eta1_2D_Fine.dat' u 1:2:3 w circles
replot 'Eta1_2D_Spostamento.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot 'Eta1_2D_Spostamento.dat' u 1:2 pt 7 ps 0.5
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta1_2D.eps'
replot
set output '|epstopdf  Eta1_2D.eps'

set term x11
set output

set title "{/Symbol h} = 0.52"
plot 'Eta2_2D_Fine.dat' u 1:2:3  w circles
replot 'Eta2_2D_Spostamento.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot 'Eta2_2D_Spostamento.dat' u 1:2 pt 7 ps 0.5
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta2_2D.eps'
replot
set output '|epstopdf  Eta2_2D.eps'

set term x11
set output

set title "{/Symbol h} = 0.32"
plot 'Eta3_2D_Fine.dat' u 1:2:3  w circles
replot 'Eta3_2D_Spostamento.dat' u 1:2:4:5 w vector  nohead lt -1 lc 3 lw 0.5
replot 'Eta3_2D_Spostamento.dat' u 1:2 pt 7 ps 0.5
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta3_2D.eps'
replot
set output '|epstopdf  Eta3_2D.eps'

set term x11
set output

set title "{/Symbol h} = 0.22"
plot[-0.5:1.5][-0.5:1.5] 'Eta4_2D_Fine.dat' u 1:2:3  w circles
replot 'Eta4_2D_Spostamento.dat' u 1:2:4:5 w vector nohead lt -1 lc 3 lw 0.5
replot 'Eta4_2D_Spostamento.dat' u 1:2 pt 7 ps 0.5
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta4_2D.eps'
replot
set output '|epstopdf  Eta4_2D.eps'

set term x11
set output
