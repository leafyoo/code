
#!/bin/sh
while read -r line
do
	if [[ ${line} == file_lef_* ]]
	then
		file=$(echo ${line}| sed 's/file_lef_//')
	elif [[ ${line} = \[*\] ]]
    then
        section=$(echo ${line}| sed 's/^\[//'| sed 's/\]$//')
    else
        echo -e ${file}"\t"${section}"\t"${line} | sed 's/=/\t/'
    fi
done < all_orig.txt
