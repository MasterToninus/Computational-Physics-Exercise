
clear
reset

# set title "M vs beta con errore ( Vari Algoritmi)"
set key left


set xlabel "{/Symbol b}" font "Times-Italic,22" offset 0,0.5
set xrange [0.3:0.5]

set ylabel " <M>" font "Times-Italic,22" rotate by 0 offset 0.5,0
#set yrange [0:1]

plot "Metro_M.dat" using 1:2:3 title "<M> METROPOLIS" w yerrorbars
replot "Metro_M_abs.dat" using 1:2:3 title "<|M|> METROPOLIS" w yerrorbars
replot "Cluster_M.dat" using 1:2:3 title "<|M|>_{improved} CLUSTER" w yerrorbars

set parametric
set trange [-0.2:1]
const=0.4406868
replot const,t lt 7 lw 1.7 lc 0 title "{/Symbol b}_{crit}"

set terminal postscript eps size 12cm,9cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'Confronto_M_andamento.eps'
replot
set output '|epstopdf  Confronto_M_andamento.eps'

set term x11
set output
