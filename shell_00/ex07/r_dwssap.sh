cat /etc/passwd | sed '/^#/d' | sed '1d; n; d'| cut -f1 -d ':' | rev | sort -r | awk -v start=$FT_LINE1 -v end=$FT_LINE2 'NR>=start && NR<end' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./'
