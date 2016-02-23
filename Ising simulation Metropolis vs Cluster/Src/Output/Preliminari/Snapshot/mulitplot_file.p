#
#          Stacked Plot Demo
#
# Set top and bottom margins to 0 so that there is no space between plots.
# Fix left and right margins to make sure that the alignment is perfect.
# Turn off xtics for all plots except the bottom one.
# In order to leave room for axis and tic labels underneath, we ask for
# a 4-plot layout but only use the top 3 slots.
#

clear
reset

##set title "H vs step Algoritmo di Clusterpolis  (L = 100)"
set terminal postscript eps size 18cm,10cm enhanced color \
    font 'Helvetica,25' linewidth 1.5
set output 'prova.eps'

set tmargin 3
set bmargin 3
set lmargin 3
set rmargin 3
unset xtics
unset ytics

set multiplot layout 1,3 title "Auto-layout of stacked plots\n"

unset title

plot sin(x) lt 1
plot cos(x) lt 3

plot sin(x)/x lt 4

unset multiplot

set output '|epstopdf prova.eps'

set term x11
set output


