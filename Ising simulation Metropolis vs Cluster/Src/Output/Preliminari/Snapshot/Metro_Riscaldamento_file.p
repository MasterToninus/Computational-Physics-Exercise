clear
reset

##set title "H vs step Algoritmo di Clusterpolis  (L = 100)"
set terminal postscript eps size 18cm,9cm enhanced color \
    font 'Helvetica,25' linewidth 1.5
set output 'Metro_Riscaldamento.eps'

set tmargin 0
set bmargin 0
set lmargin 0
set rmargin 0
unset xtics
unset ytics
unset key

set multiplot layout 1,3

#
set title "t = 0 " offset 0,-0.75
set size ratio -1

set size 0.33333333,1
set origin 0.0,0.0
set lmargin 0
set rmargin 0

set view map
unset surface
set style data pm3d

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
unset colorbox
splot 'Metro_Riscaldamento_0.dat'

#
set title "t = 1"
set size ratio -1


set origin 0.33333333333333333,0.0
set lmargin 0
set rmargin 0

set view map
unset surface
set style data pm3d

unset xlabel
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'Metro_Riscaldamento_1.dat'

#
set title "t = 5 "
set size ratio -1


set origin 0.66666666666666,0.0
set lmargin 0
set rmargin 0


set view map
unset surface
set style data pm3d

unset xlabel
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'Metro_Riscaldamento_5.dat'
#

unset multiplot
set nomultiplot
set output '|epstopdf Metro_Riscaldamento.eps'
set term x11
set output

	

