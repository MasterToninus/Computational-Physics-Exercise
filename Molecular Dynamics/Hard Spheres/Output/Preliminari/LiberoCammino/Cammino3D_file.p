
clear
reset
set size ratio -1

L = 1
set xtics L
set ytics L
set ztics L
unset border
unset tics
set hidden3d
set view 80,30


splot 'Box3D_v2.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6)) index 0 notitle  w vector nohead  lc 0 lt -1 lw 1
replot 'Moto_P3D_Eta0.dat' w lines title "{/Symbol h} = 0.62" 
replot 'Moto_P3D_Eta1.dat' w lines title "{/Symbol h} = 0.52"
replot 'Moto_P3D_Eta2.dat' w lines title "{/Symbol h} = 0.42"
replot 'Moto_P3D_Eta3.dat' w lines title "{/Symbol h} = 0.32"
replot 'Moto_P3D_Eta4.dat' w lines title "{/Symbol h} = 0.22"
replot 'Box3D_v2.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6)) index 1 notitle  w vector nohead  lc 0 lt -0 lw 1

set terminal postscript eps size 10cm,10cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror
set ztics nomirror

set output 'Lc_3D.eps'
replot
set output '|epstopdf  Lc_3D.eps'

set term x11
set output
