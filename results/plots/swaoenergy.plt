f="swapenergy"

set xrange [-0.5:3.5]

set xlabel "Quality Level"
set ylabel "Normalized Energy Cost (a.u)"
set xrange [-0.5:3.5]
set yrange [.4:1]
set xtics 1
set boxwidth 0.25
set style fill pattern 1

set terminal pdf font 'Helvetica,8'
set key bottom right

set output "swaptions-energy.pdf"
plot f u 1:2 with boxes t ''
