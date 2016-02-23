## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
#set key left top

set xlabel "r [{/Symbol s}]" font "Times-Italic,28" #offset 0,1.5
set xrange [0.9:2.5]

set ylabel "[{/Symbol e}]" font "Times-Italic,28" offset 1.5,0 #rotate by 0
set yrange [-2.5:3]
set trange [-5:1]

u(x) = 4 *(x**(-12) - x**(-6));
F(x) = 24 *(2*x**(-13) - x**(-7));


plot u(x) 	title " Potenziale"   lt 2 lc 1 lw 1.5
replot F(x) title " Forza"   lt 2 lc 2 lw 1.5

	replot (u(x) - u(2.5) + (x-2.5)*F(2.5)) title " Potenziale tagliato" lt 1 lc 1 lw 2.2	
	replot (F(x) - F(2.5)) title "Forza Tagliata" lt 1 lc 2 lw 2.2	


set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'potenziale.eps'
replot
set output '|epstopdf  potenziale.eps'

set term x11
set output
