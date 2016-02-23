clear
reset
set title "<S0 St> vs t (Cluster)" 
set xlabel "t"
set xrange [0:40]
set ylabel "<S0 St>"
#set yrange [-0.001:0.06]
unset key
plot 'molti_S0Stvst_.dat' index 0 using 1:2:3 with yerrorbars
A_0=1
f_0(x) = exp(-x/A_0)
f_0(x) = exp(-x/A_0)
N=5
fit f_0(x) 'molti_S0Stvst_.dat' index 0 every ::0::N using 1:2:3 via A_0
replot f_0(x)
replot 'molti_S0Stvst_.dat' index 1 using 1:2:3 with yerrorbars
A_1=1
f_1(x) = exp(-x/A_1)
N=5
fit f_1(x) 'molti_S0Stvst_.dat' index 1 every ::0::N using 1:2:3 via A_1
replot f_1(x)
replot 'molti_S0Stvst_.dat' index 2 using 1:2:3 with yerrorbars
A_2=1
f_2(x) = exp(-x/A_2)
N=5
fit f_2(x) 'molti_S0Stvst_.dat' index 2 every ::0::N using 1:2:3 via A_2
replot f_2(x)
replot 'molti_S0Stvst_.dat' index 3 using 1:2:3 with yerrorbars
A_3=1
f_3(x) = exp(-x/A_3)
N=5
fit f_3(x) 'molti_S0Stvst_.dat' index 3 every ::0::N using 1:2:3 via A_3
replot f_3(x)
replot 'molti_S0Stvst_.dat' index 4 using 1:2:3 with yerrorbars
A_4=1
f_4(x) = exp(-x/A_4)
N=5
fit f_4(x) 'molti_S0Stvst_.dat' index 4 every ::0::N using 1:2:3 via A_4
replot f_4(x)
replot 'molti_S0Stvst_.dat' index 5 using 1:2:3 with yerrorbars
A_5=1
f_5(x) = exp(-x/A_5)
N=5
fit f_5(x) 'molti_S0Stvst_.dat' index 5 every ::0::N using 1:2:3 via A_5
replot f_5(x)
replot 'molti_S0Stvst_.dat' index 6 using 1:2:3 with yerrorbars
A_6=1
f_6(x) = exp(-x/A_6)
N=5
fit f_6(x) 'molti_S0Stvst_.dat' index 6 every ::0::N using 1:2:3 via A_6
replot f_6(x)
replot 'molti_S0Stvst_.dat' index 7 using 1:2:3 with yerrorbars
A_7=1
f_7(x) = exp(-x/A_7)
N=5
fit f_7(x) 'molti_S0Stvst_.dat' index 7 every ::0::N using 1:2:3 via A_7
replot f_7(x)
replot 'molti_S0Stvst_.dat' index 8 using 1:2:3 with yerrorbars
A_8=1
f_8(x) = exp(-x/A_8)
N=5
fit f_8(x) 'molti_S0Stvst_.dat' index 8 every ::0::N using 1:2:3 via A_8
replot f_8(x)
replot 'molti_S0Stvst_.dat' index 9 using 1:2:3 with yerrorbars
A_9=1
f_9(x) = exp(-x/A_9)
N=5
fit f_9(x) 'molti_S0Stvst_.dat' index 9 every ::0::N using 1:2:3 via A_9
replot f_9(x)
replot 'molti_S0Stvst_.dat' index 10 using 1:2:3 with yerrorbars
A_10=1
f_10(x) = exp(-x/A_10)
N=5
fit f_10(x) 'molti_S0Stvst_.dat' index 10 every ::0::N using 1:2:3 via A_10
replot f_10(x)
replot 'molti_S0Stvst_.dat' index 11 using 1:2:3 with yerrorbars
A_11=1
f_11(x) = exp(-x/A_11)
N=5
fit f_11(x) 'molti_S0Stvst_.dat' index 11 every ::0::N using 1:2:3 via A_11
replot f_11(x)
replot 'molti_S0Stvst_.dat' index 12 using 1:2:3 with yerrorbars
A_12=1
f_12(x) = exp(-x/A_12)
N=5
fit f_12(x) 'molti_S0Stvst_.dat' index 12 every ::0::N using 1:2:3 via A_12
replot f_12(x)
replot 'molti_S0Stvst_.dat' index 13 using 1:2:3 with yerrorbars
A_13=1
f_13(x) = exp(-x/A_13)
N=5
fit f_13(x) 'molti_S0Stvst_.dat' index 13 every ::0::N using 1:2:3 via A_13
replot f_13(x)
replot 'molti_S0Stvst_.dat' index 14 using 1:2:3 with yerrorbars
A_14=1
f_14(x) = exp(-x/A_14)
N=5
fit f_14(x) 'molti_S0Stvst_.dat' index 14 every ::0::N using 1:2:3 via A_14
replot f_14(x)
replot 'molti_S0Stvst_.dat' index 15 using 1:2:3 with yerrorbars
A_15=1
f_15(x) = exp(-x/A_15)
N=5
fit f_15(x) 'molti_S0Stvst_.dat' index 15 every ::0::N using 1:2:3 via A_15
replot f_15(x)
replot 'molti_S0Stvst_.dat' index 16 using 1:2:3 with yerrorbars
A_16=1
f_16(x) = exp(-x/A_16)
N=5
fit f_16(x) 'molti_S0Stvst_.dat' index 16 every ::0::N using 1:2:3 via A_16
replot f_16(x)
replot 'molti_S0Stvst_.dat' index 17 using 1:2:3 with yerrorbars
A_17=1
f_17(x) = exp(-x/A_17)
N=5
fit f_17(x) 'molti_S0Stvst_.dat' index 17 every ::0::N using 1:2:3 via A_17
replot f_17(x)
replot 'molti_S0Stvst_.dat' index 18 using 1:2:3 with yerrorbars
A_18=1
f_18(x) = exp(-x/A_18)
N=5
fit f_18(x) 'molti_S0Stvst_.dat' index 18 every ::0::N using 1:2:3 via A_18
replot f_18(x)
replot 'molti_S0Stvst_.dat' index 19 using 1:2:3 with yerrorbars
A_19=1
f_19(x) = exp(-x/A_19)
N=5
fit f_19(x) 'molti_S0Stvst_.dat' index 19 every ::0::N using 1:2:3 via A_19
replot f_19(x)
replot 'molti_S0Stvst_.dat' index 20 using 1:2:3 with yerrorbars
A_20=1
f_20(x) = exp(-x/A_20)
N=5
fit f_20(x) 'molti_S0Stvst_.dat' index 20 every ::0::N using 1:2:3 via A_20
replot f_20(x)
replot 'molti_S0Stvst_.dat' index 21 using 1:2:3 with yerrorbars
A_21=1
f_21(x) = exp(-x/A_21)
N=5
fit f_21(x) 'molti_S0Stvst_.dat' index 21 every ::0::N using 1:2:3 via A_21
replot f_21(x)
replot 'molti_S0Stvst_.dat' index 22 using 1:2:3 with yerrorbars
A_22=1
f_22(x) = exp(-x/A_22)
N=5
fit f_22(x) 'molti_S0Stvst_.dat' index 22 every ::0::N using 1:2:3 via A_22
replot f_22(x)
replot 'molti_S0Stvst_.dat' index 23 using 1:2:3 with yerrorbars
A_23=1
f_23(x) = exp(-x/A_23)
N=5
fit f_23(x) 'molti_S0Stvst_.dat' index 23 every ::0::N using 1:2:3 via A_23
replot f_23(x)
replot 'molti_S0Stvst_.dat' index 24 using 1:2:3 with yerrorbars
A_24=1
f_24(x) = exp(-x/A_24)
N=5
fit f_24(x) 'molti_S0Stvst_.dat' index 24 every ::0::N using 1:2:3 via A_24
replot f_24(x)
replot 'molti_S0Stvst_.dat' index 25 using 1:2:3 with yerrorbars
A_25=1
f_25(x) = exp(-x/A_25)
N=5
fit f_25(x) 'molti_S0Stvst_.dat' index 25 every ::0::N using 1:2:3 via A_25
replot f_25(x)
replot 'molti_S0Stvst_.dat' index 26 using 1:2:3 with yerrorbars
A_26=1
f_26(x) = exp(-x/A_26)
N=5
fit f_26(x) 'molti_S0Stvst_.dat' index 26 every ::0::N using 1:2:3 via A_26
replot f_26(x)
replot 'molti_S0Stvst_.dat' index 27 using 1:2:3 with yerrorbars
A_27=1
f_27(x) = exp(-x/A_27)
N=5
fit f_27(x) 'molti_S0Stvst_.dat' index 27 every ::0::N using 1:2:3 via A_27
replot f_27(x)
replot 'molti_S0Stvst_.dat' index 28 using 1:2:3 with yerrorbars
A_28=1
f_28(x) = exp(-x/A_28)
N=5
fit f_28(x) 'molti_S0Stvst_.dat' index 28 every ::0::N using 1:2:3 via A_28
replot f_28(x)
replot 'molti_S0Stvst_.dat' index 29 using 1:2:3 with yerrorbars
A_29=1
f_29(x) = exp(-x/A_29)
N=5
fit f_29(x) 'molti_S0Stvst_.dat' index 29 every ::0::N using 1:2:3 via A_29
replot f_29(x)
replot 'molti_S0Stvst_.dat' index 30 using 1:2:3 with yerrorbars
A_30=1
f_30(x) = exp(-x/A_30)
N=5
fit f_30(x) 'molti_S0Stvst_.dat' index 30 every ::0::N using 1:2:3 via A_30
replot f_30(x)
replot 'molti_S0Stvst_.dat' index 31 using 1:2:3 with yerrorbars
A_31=1
f_31(x) = exp(-x/A_31)
N=5
fit f_31(x) 'molti_S0Stvst_.dat' index 31 every ::0::N using 1:2:3 via A_31
replot f_31(x)
replot 'molti_S0Stvst_.dat' index 32 using 1:2:3 with yerrorbars
A_32=1
f_32(x) = exp(-x/A_32)
N=5
fit f_32(x) 'molti_S0Stvst_.dat' index 32 every ::0::N using 1:2:3 via A_32
replot f_32(x)
replot 'molti_S0Stvst_.dat' index 33 using 1:2:3 with yerrorbars
A_33=1
f_33(x) = exp(-x/A_33)
N=5
fit f_33(x) 'molti_S0Stvst_.dat' index 33 every ::0::N using 1:2:3 via A_33
replot f_33(x)
replot 'molti_S0Stvst_.dat' index 34 using 1:2:3 with yerrorbars
A_34=1
f_34(x) = exp(-x/A_34)
N=5
fit f_34(x) 'molti_S0Stvst_.dat' index 34 every ::0::N using 1:2:3 via A_34
replot f_34(x)
replot 'molti_S0Stvst_.dat' index 35 using 1:2:3 with yerrorbars
A_35=1
f_35(x) = exp(-x/A_35)
N=5
fit f_35(x) 'molti_S0Stvst_.dat' index 35 every ::0::N using 1:2:3 via A_35
replot f_35(x)
replot 'molti_S0Stvst_.dat' index 36 using 1:2:3 with yerrorbars
A_36=1
f_36(x) = exp(-x/A_36)
N=20
fit f_36(x) 'molti_S0Stvst_.dat' index 36 every ::0::N using 1:2:3 via A_36
replot f_36(x)
replot 'molti_S0Stvst_.dat' index 37 using 1:2:3 with yerrorbars
A_37=1
f_37(x) = exp(-x/A_37)
N=20
fit f_37(x) 'molti_S0Stvst_.dat' index 37 every ::0::N using 1:2:3 via A_37
replot f_37(x)
replot 'molti_S0Stvst_.dat' index 38 using 1:2:3 with yerrorbars
A_38=1
f_38(x) = exp(-x/A_38)
N=20
fit f_38(x) 'molti_S0Stvst_.dat' index 38 every ::0::N using 1:2:3 via A_38
replot f_38(x)
replot 'molti_S0Stvst_.dat' index 39 using 1:2:3 with yerrorbars
A_39=1
f_39(x) = exp(-x/A_39)
N=20
fit f_39(x) 'molti_S0Stvst_.dat' index 39 every ::0::N using 1:2:3 via A_39
replot f_39(x)
replot 'molti_S0Stvst_.dat' index 40 using 1:2:3 with yerrorbars
A_40=1
f_40(x) = exp(-x/A_40)
N=20
fit f_40(x) 'molti_S0Stvst_.dat' index 40 every ::0::N using 1:2:3 via A_40
replot f_40(x)
replot 'molti_S0Stvst_.dat' index 41 using 1:2:3 with yerrorbars
A_41=1
f_41(x) = exp(-x/A_41)
N=20
fit f_41(x) 'molti_S0Stvst_.dat' index 41 every ::0::N using 1:2:3 via A_41
replot f_41(x)
replot 'molti_S0Stvst_.dat' index 42 using 1:2:3 with yerrorbars
A_42=1
f_42(x) = exp(-x/A_42)
N=20
fit f_42(x) 'molti_S0Stvst_.dat' index 42 every ::0::N using 1:2:3 via A_42
replot f_42(x)
replot 'molti_S0Stvst_.dat' index 43 using 1:2:3 with yerrorbars
A_43=1
f_43(x) = exp(-x/A_43)
N=20
fit f_43(x) 'molti_S0Stvst_.dat' index 43 every ::0::N using 1:2:3 via A_43
replot f_43(x)
replot 'molti_S0Stvst_.dat' index 44 using 1:2:3 with yerrorbars
A_44=1
f_44(x) = exp(-x/A_44)
N=20
fit f_44(x) 'molti_S0Stvst_.dat' index 44 every ::0::N using 1:2:3 via A_44
replot f_44(x)
replot 'molti_S0Stvst_.dat' index 45 using 1:2:3 with yerrorbars
A_45=1
f_45(x) = exp(-x/A_45)
N=20
fit f_45(x) 'molti_S0Stvst_.dat' index 45 every ::0::N using 1:2:3 via A_45
replot f_45(x)
replot 'molti_S0Stvst_.dat' index 46 using 1:2:3 with yerrorbars
A_46=1
f_46(x) = exp(-x/A_46)
N=20
fit f_46(x) 'molti_S0Stvst_.dat' index 46 every ::0::N using 1:2:3 via A_46
replot f_46(x)
replot 'molti_S0Stvst_.dat' index 47 using 1:2:3 with yerrorbars
A_47=1
f_47(x) = exp(-x/A_47)
N=20
fit f_47(x) 'molti_S0Stvst_.dat' index 47 every ::0::N using 1:2:3 via A_47
replot f_47(x)
replot 'molti_S0Stvst_.dat' index 48 using 1:2:3 with yerrorbars
A_48=1
f_48(x) = exp(-x/A_48)
N=20
fit f_48(x) 'molti_S0Stvst_.dat' index 48 every ::0::N using 1:2:3 via A_48
replot f_48(x)
replot 'molti_S0Stvst_.dat' index 49 using 1:2:3 with yerrorbars
A_49=1
f_49(x) = exp(-x/A_49)
N=20
fit f_49(x) 'molti_S0Stvst_.dat' index 49 every ::0::N using 1:2:3 via A_49
replot f_49(x)
replot 'molti_S0Stvst_.dat' index 50 using 1:2:3 with yerrorbars
A_50=1
f_50(x) = exp(-x/A_50)
N=20
fit f_50(x) 'molti_S0Stvst_.dat' index 50 every ::0::N using 1:2:3 via A_50
replot f_50(x)
replot 'molti_S0Stvst_.dat' index 51 using 1:2:3 with yerrorbars
A_51=1
f_51(x) = exp(-x/A_51)
N=20
fit f_51(x) 'molti_S0Stvst_.dat' index 51 every ::0::N using 1:2:3 via A_51
replot f_51(x)
replot 'molti_S0Stvst_.dat' index 52 using 1:2:3 with yerrorbars
A_52=1
f_52(x) = exp(-x/A_52)
N=20
fit f_52(x) 'molti_S0Stvst_.dat' index 52 every ::0::N using 1:2:3 via A_52
replot f_52(x)
replot 'molti_S0Stvst_.dat' index 53 using 1:2:3 with yerrorbars
A_53=1
f_53(x) = exp(-x/A_53)
N=20
fit f_53(x) 'molti_S0Stvst_.dat' index 53 every ::0::N using 1:2:3 via A_53
replot f_53(x)
replot 'molti_S0Stvst_.dat' index 54 using 1:2:3 with yerrorbars
A_54=1
f_54(x) = exp(-x/A_54)
N=20
fit f_54(x) 'molti_S0Stvst_.dat' index 54 every ::0::N using 1:2:3 via A_54
replot f_54(x)
replot 'molti_S0Stvst_.dat' index 55 using 1:2:3 with yerrorbars
A_55=1
f_55(x) = exp(-x/A_55)
N=20
fit f_55(x) 'molti_S0Stvst_.dat' index 55 every ::0::N using 1:2:3 via A_55
replot f_55(x)
replot 'molti_S0Stvst_.dat' index 56 using 1:2:3 with yerrorbars
A_56=1
f_56(x) = exp(-x/A_56)
N=20
fit f_56(x) 'molti_S0Stvst_.dat' index 56 every ::0::N using 1:2:3 via A_56
replot f_56(x)
replot 'molti_S0Stvst_.dat' index 57 using 1:2:3 with yerrorbars
A_57=1
f_57(x) = exp(-x/A_57)
N=20
fit f_57(x) 'molti_S0Stvst_.dat' index 57 every ::0::N using 1:2:3 via A_57
replot f_57(x)
replot 'molti_S0Stvst_.dat' index 58 using 1:2:3 with yerrorbars
A_58=1
f_58(x) = exp(-x/A_58)
N=20
fit f_58(x) 'molti_S0Stvst_.dat' index 58 every ::0::N using 1:2:3 via A_58
replot f_58(x)
replot 'molti_S0Stvst_.dat' index 59 using 1:2:3 with yerrorbars
A_59=1
f_59(x) = exp(-x/A_59)
N=20
fit f_59(x) 'molti_S0Stvst_.dat' index 59 every ::0::N using 1:2:3 via A_59
replot f_59(x)
replot 'molti_S0Stvst_.dat' index 60 using 1:2:3 with yerrorbars
A_60=1
f_60(x) = exp(-x/A_60)
N=20
fit f_60(x) 'molti_S0Stvst_.dat' index 60 every ::0::N using 1:2:3 via A_60
replot f_60(x)
replot 'molti_S0Stvst_.dat' index 61 using 1:2:3 with yerrorbars
A_61=1
f_61(x) = exp(-x/A_61)
N=20
fit f_61(x) 'molti_S0Stvst_.dat' index 61 every ::0::N using 1:2:3 via A_61
replot f_61(x)
replot 'molti_S0Stvst_.dat' index 62 using 1:2:3 with yerrorbars
A_62=1
f_62(x) = exp(-x/A_62)
N=20
fit f_62(x) 'molti_S0Stvst_.dat' index 62 every ::0::N using 1:2:3 via A_62
replot f_62(x)
replot 'molti_S0Stvst_.dat' index 63 using 1:2:3 with yerrorbars
A_63=1
f_63(x) = exp(-x/A_63)
N=20
fit f_63(x) 'molti_S0Stvst_.dat' index 63 every ::0::N using 1:2:3 via A_63
replot f_63(x)
replot 'molti_S0Stvst_.dat' index 64 using 1:2:3 with yerrorbars
A_64=1
f_64(x) = exp(-x/A_64)
N=20
fit f_64(x) 'molti_S0Stvst_.dat' index 64 every ::0::N using 1:2:3 via A_64
replot f_64(x)
replot 'molti_S0Stvst_.dat' index 65 using 1:2:3 with yerrorbars
A_65=1
f_65(x) = exp(-x/A_65)
N=20
fit f_65(x) 'molti_S0Stvst_.dat' index 65 every ::0::N using 1:2:3 via A_65
replot f_65(x)
replot 'molti_S0Stvst_.dat' index 66 using 1:2:3 with yerrorbars
A_66=1
f_66(x) = exp(-x/A_66)
N=20
fit f_66(x) 'molti_S0Stvst_.dat' index 66 every ::0::N using 1:2:3 via A_66
replot f_66(x)
replot 'molti_S0Stvst_.dat' index 67 using 1:2:3 with yerrorbars
A_67=1
f_67(x) = exp(-x/A_67)
N=20
fit f_67(x) 'molti_S0Stvst_.dat' index 67 every ::0::N using 1:2:3 via A_67
replot f_67(x)
replot 'molti_S0Stvst_.dat' index 68 using 1:2:3 with yerrorbars
A_68=1
f_68(x) = exp(-x/A_68)
N=20
fit f_68(x) 'molti_S0Stvst_.dat' index 68 every ::0::N using 1:2:3 via A_68
replot f_68(x)
replot 'molti_S0Stvst_.dat' index 69 using 1:2:3 with yerrorbars
A_69=1
f_69(x) = exp(-x/A_69)
N=20
fit f_69(x) 'molti_S0Stvst_.dat' index 69 every ::0::N using 1:2:3 via A_69
replot f_69(x)
replot 'molti_S0Stvst_.dat' index 70 using 1:2:3 with yerrorbars
A_70=1
f_70(x) = exp(-x/A_70)
N=20
fit f_70(x) 'molti_S0Stvst_.dat' index 70 every ::0::N using 1:2:3 via A_70
replot f_70(x)
replot 'molti_S0Stvst_.dat' index 71 using 1:2:3 with yerrorbars
A_71=1
f_71(x) = exp(-x/A_71)
N=20
fit f_71(x) 'molti_S0Stvst_.dat' index 71 every ::0::N using 1:2:3 via A_71
replot f_71(x)
replot 'molti_S0Stvst_.dat' index 72 using 1:2:3 with yerrorbars
A_72=1
f_72(x) = exp(-x/A_72)
N=20
fit f_72(x) 'molti_S0Stvst_.dat' index 72 every ::0::N using 1:2:3 via A_72
replot f_72(x)
replot 'molti_S0Stvst_.dat' index 73 using 1:2:3 with yerrorbars
A_73=1
f_73(x) = exp(-x/A_73)
N=20
fit f_73(x) 'molti_S0Stvst_.dat' index 73 every ::0::N using 1:2:3 via A_73
replot f_73(x)
replot 'molti_S0Stvst_.dat' index 74 using 1:2:3 with yerrorbars
A_74=1
f_74(x) = exp(-x/A_74)
N=20
fit f_74(x) 'molti_S0Stvst_.dat' index 74 every ::0::N using 1:2:3 via A_74
replot f_74(x)
replot 'molti_S0Stvst_.dat' index 75 using 1:2:3 with yerrorbars
A_75=1
f_75(x) = exp(-x/A_75)
N=20
fit f_75(x) 'molti_S0Stvst_.dat' index 75 every ::0::N using 1:2:3 via A_75
replot f_75(x)
replot 'molti_S0Stvst_.dat' index 76 using 1:2:3 with yerrorbars
A_76=1
f_76(x) = exp(-x/A_76)
N=20
fit f_76(x) 'molti_S0Stvst_.dat' index 76 every ::0::N using 1:2:3 via A_76
replot f_76(x)
replot 'molti_S0Stvst_.dat' index 77 using 1:2:3 with yerrorbars
A_77=1
f_77(x) = exp(-x/A_77)
N=20
fit f_77(x) 'molti_S0Stvst_.dat' index 77 every ::0::N using 1:2:3 via A_77
replot f_77(x)
replot 'molti_S0Stvst_.dat' index 78 using 1:2:3 with yerrorbars
A_78=1
f_78(x) = exp(-x/A_78)
N=20
fit f_78(x) 'molti_S0Stvst_.dat' index 78 every ::0::N using 1:2:3 via A_78
replot f_78(x)
replot 'molti_S0Stvst_.dat' index 79 using 1:2:3 with yerrorbars
A_79=1
f_79(x) = exp(-x/A_79)
N=20
fit f_79(x) 'molti_S0Stvst_.dat' index 79 every ::0::N using 1:2:3 via A_79
replot f_79(x)
replot 'molti_S0Stvst_.dat' index 80 using 1:2:3 with yerrorbars
A_80=1
f_80(x) = exp(-x/A_80)
N=20
fit f_80(x) 'molti_S0Stvst_.dat' index 80 every ::0::N using 1:2:3 via A_80
replot f_80(x)
print A_0
print A_1
print A_2
print A_3
print A_4
print A_5
print A_6
print A_7
print A_8
print A_9
print A_10
print A_11
print A_12
print A_13
print A_14
print A_15
print A_16
print A_17
print A_18
print A_19
print A_20
print A_21
print A_22
print A_23
print A_24
print A_25
print A_26
print A_27
print A_28
print A_29
print A_30
print A_31
print A_32
print A_33
print A_34
print A_35
print A_36
print A_37
print A_38
print A_39
print A_40
print A_41
print A_42
print A_43
print A_44
print A_45
print A_46
print A_47
print A_48
print A_49
print A_50
print A_51
print A_52
print A_53
print A_54
print A_55
print A_56
print A_57
print A_58
print A_59
print A_60
print A_61
print A_62
print A_63
print A_64
print A_65
print A_66
print A_67
print A_68
print A_69
print A_70
print A_71
print A_72
print A_73
print A_74
print A_75
print A_76
print A_77
print A_78
print A_79
print A_80
