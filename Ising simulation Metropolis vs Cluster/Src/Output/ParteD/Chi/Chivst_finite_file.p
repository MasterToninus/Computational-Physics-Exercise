## prototipo di grafico x y con barra di errore

clear
reset

nu=1
gamma=1.75

L_0=200
X_0(x)= x*L_0**(1/nu)
Y_0(x)= L_0**(-gamma/nu)*x

plot[-10:20] "Chivst_N200.dat" u (X_0($1)):(Y_0($2)):(Y_0($3))	 title "L = 200" w yerrorbars	lw 2 

L_1=120
X_1(x)= x*L_1**(1/nu)
Y_1(x)= L_1**(-gamma/nu)*x
replot "Chivst_N120.dat" u (X_1($1)):(Y_1($2)):(Y_1($3))	 title "L = 120" w yerrorbars	lw 2 

L_2=105
X_2(x)= x*L_2**(1/nu)
Y_2(x)= L_2**(-gamma/nu)*x
replot "Chivst_N105.dat" u (X_2($1)):(Y_2($2)):(Y_2($3))	 title "L = 105" w yerrorbars	lw 2 

L_3=90
X_3(x)= x*L_3**(1/nu)
Y_3(x)= L_3**(-gamma/nu)*x
replot "Chivst_N90.dat" u (X_3($1)):(Y_3($2)):(Y_3($3))	 title "L = 90" w yerrorbars	lw 2 

L_4=75
X_4(x)= x*L_4**(1/nu)
Y_4(x)= L_4**(-gamma/nu)*x
replot "Chivst_N75.dat" u (X_4($1)):(Y_4($2)):(Y_4($3))	 title "L = 75" w yerrorbars	lw 2 

L_5=60
X_5(x)= x*L_5**(1/nu)
Y_5(x)= L_5**(-gamma/nu)*x
replot "Chivst_N60.dat" u (X_5($1)):(Y_5($2)):(Y_5($3))	 title "L = 60" w yerrorbars	lw 2 

L_6=45
X_6(x)= x*L_6**(1/nu)
Y_6(x)= L_6**(-gamma/nu)*x
#	replot "Chivst_N45.dat" u (X_6($1)):(Y_6($2)):(Y_6($3))	 title "L = 45" w yerrorbars	lw 2 

L_7=30
X_7(x)= x*L_7**(1/nu)
Y_7(x)= L_7**(-gamma/nu)*x
replot "Chivst_N30.dat"  u (X_7($1)):(Y_7($2)):(Y_7($3))	 title "L = 30" w yerrorbars	lw 2 lc 17

L_8=15
X_8(x)= x*L_8**(1/nu)
Y_8(x)= L_8**(-gamma/nu)*x
#	replot "Chivst_N15.dat"  u (X_8($1)):(Y_8($2)):(Y_8($3))	 title "L = 15" w yerrorbars	lw 2 

set terminal postscript eps size 18cm,9cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

#set title "TauH vs X (serie trocata a step 10000)"

set xlabel "x =  t L^{1/{ /Symbol n}}" font "Times-Italic,28" offset 0.5, 0.5
#set xrange [-0.125: 0.125]
set xtics 5
set mxtic 2


set ylabel " {/Symbol c}_{fs}(x)" font "Times-Italic,28" offset 2,0 rotate by 90
set yrange [0:0.06]
set ytics 0.02
set mytic 2

set xtics nomirror
set ytics nomirror

set grid
#set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt 7 lw 1

set output 'Chivst_finite.eps'
replot
set output '|epstopdf  Chivst_finite.eps'

set term x11
set output

