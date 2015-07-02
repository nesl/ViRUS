f='whetsone'
set ylabel "Normalized energy cost per iteration (a.u.)"
set xlabel "Number of iterations (#)"
set yrange [.4:1]
set key center right
set terminal pdf font 'Helvetica'
set output "whetstone.pdf"
plot f u 1:2 w lp smooth bezier lw 4 t 'Quality 0', f u 1:3 w lp smooth bezier lw 4 t 'Quality 1', f u 1:4 w lp smooth bezier  lw 4 t 'Quality 2', f u 1:5 w lp smooth bezier  lw 4 t 'Quality 3'
