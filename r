if [[ -z $1 ]];
then jobs
else 
    filter=$(echo $@ | sed 's/\s/.*/g')
    list=$(jobs | grep -i $filter)
    if [[ -z $list ]];
    then echo Nothing found
    elif [[ $(echo "$list" | wc -l) -gt 1 ]];
    then echo "$list"
    else
        fg $(echo $list | grep -Po '\[\d+\]' | tr -d '[]' )
    fi
fi

