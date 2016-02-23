
clear
reset
set size ratio -1

L = 1
set xtics L
set ytics L
unset border
unset tics
unset key

set hidden3d
set title "{/Symbol h} = 0.680"

splot 'Box3D_v2.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6)) index 0 notitle  w vector nohead  lc 0 lt -1 lw 1
relot 'Eta0_3D_Fine.dat' pt 7
replot 'Eta0_3D_Spostamento.dat' u 1:2:3:5:6:7 w vector
replot 'Eta0_3D_Spostamento.dat' u 1:2:3 pt 7 ps 0.5
replot 'Box3D_v2.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6)) index 1 notitle  w vector nohead  lc 0 lt -0 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta0_3D.eps'
replot
set output '|epstopdf  Eta0_3D.eps'

set term x11
set output

set title "{/Symbol h} = 0.573"
splot 'Eta1_3D_Fine.dat' pt 7
replot 'Eta1_3D_Spostamento.dat' u 1:2:3:5:6:7 w vector
replot 'Eta1_3D_Spostamento.dat' u 1:2:3 pt 7 ps 0.5
replot 'Box3D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta1_3D.eps'
replot
set output '|epstopdf  Eta1_3D.eps'

set term x11
set output

set title "{/Symbol h} = 0.465"
splot 'Eta2_3D_Fine.dat' pt 7
replot 'Eta2_3D_Spostamento.dat' u 1:2:3:5:6:7 w vector
replot 'Eta2_3D_Spostamento.dat' u 1:2:3 pt 7 ps 0.5
replot 'Box3D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta2_3D.eps'
replot
set output '|epstopdf  Eta2_3D.eps'

set term x11
set output

set title "{/Symbol h} = 0.358"
splot 'Eta3_3D_Fine.dat' pt 7
replot 'Eta3_3D_Spostamento.dat' u 1:2:3:5:6:7 w vector
replot 'Eta3_3D_Spostamento.dat' u 1:2:3 pt 7 ps 0.5
replot 'Box3D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta3_3D.eps'
replot
set output '|epstopdf  Eta3_3D.eps'

set term x11
set output

set title "{/Symbol h} = 0.25"
splot 'Eta4_3D_Fine.dat' pt 7
replot 'Eta4_3D_Spostamento.dat' u 1:2:3:5:6:7 w vector
replot 'Eta4_3D_Spostamento.dat' u 1:2 :3 pt 7 ps 0.5
replot 'Box3D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0 lt -1 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'Eta4_3D.eps'
replot
set output '|epstopdf  Eta4_3D.eps'

set term x11
set output
