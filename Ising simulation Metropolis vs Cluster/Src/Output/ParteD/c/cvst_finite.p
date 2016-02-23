## prototipo di grafico x y con barra di errore

clear
reset

nu=1
alpha= 0.3

L_0=200
X_0(x)= x*L_0**(1/nu)
Y_0(x)= L_0**(-alpha/nu)*x

plot[-10:10] "cvst_N200.dat" u (X_0($1)):(Y_0($2)):(Y_0($3))	 title "L = 200" w yerrorbars	lw 2 

L_1=120
X_1(x)= x*L_1**(1/nu)
Y_1(x)= L_1**(-alpha/nu)*x
replot "cvst_N120.dat" u (X_1($1)):(Y_1($2)):(Y_1($3))	 title "L = 120" w yerrorbars	lw 2 

L_2=105
X_2(x)= x*L_2**(1/nu)
Y_2(x)= L_2**(-alpha/nu)*x
replot "cvst_N105.dat" u (X_2($1)):(Y_2($2)):(Y_2($3))	 title "L = 105" w yerrorbars	lw 2 

L_3=90
X_3(x)= x*L_3**(1/nu)
Y_3(x)= L_3**(-alpha/nu)*x
replot "cvst_N90.dat" u (X_3($1)):(Y_3($2)):(Y_3($3))	 title "L = 90" w yerrorbars	lw 2 

L_4=75
X_4(x)= x*L_4**(1/nu)
Y_4(x)= L_4**(-alpha/nu)*x
replot "cvst_N75.dat" u (X_4($1)):(Y_4($2)):(Y_4($3))	 title "L = 75" w yerrorbars	lw 2 

L_5=60
X_5(x)= x*L_5**(1/nu)
Y_5(x)= L_5**(-alpha/nu)*x
replot "cvst_N60.dat" u (X_5($1)):(Y_5($2)):(Y_5($3))	 title "L = 60" w yerrorbars	lw 2 

L_6=45
X_6(x)= x*L_6**(1/nu)
Y_6(x)= L_6**(-alpha/nu)*x
replot "cvst_N45.dat" u (X_6($1)):(Y_6($2)):(Y_6($3))	 title "L = 45" w yerrorbars	lw 2 

#	L_7=30
#	X_7(x)= x*L_7**(1/nu)
#	Y_7(x)= L_7**(-alpha/nu)*x
#	replot "cvst_N30.dat"  u (X_7($1)):(Y_7($2)):(Y_7($3))	 title "L = 30" w yerrorbars	lw 2 

#	L_8=15
#	X_8(x)= x*L_8**(1/nu)
#	Y_8(x)= L_8**(-alpha/nu)*x
#	replot "cvst_N15.dat"  u (X_8($1)):(Y_8($2)):(Y_8($3))	 title "L = 15" w yerrorbars	lw 2 



