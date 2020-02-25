#!/bin/bash

IFS=$'\n'

dir_name=$1
extension=$2
backup_dir=$3
zip_name=$4

mkdir $backup_dir

files=()
files+=$(find $dir_name -name "*."$extension)

for file in $files; do
    basefile=$(basename -- "$file")
    if [[ -f $backup_dir"/"$basefile ]]; then
        cnt=1
         
        filename="${basefile%.*}"
        extension="${basefile##*.}"
	        
        while [[ -f $backup_dir"/"$filename"("$cnt")."$extension ]]; do
            cnt=$(( $cnt+1 ))
        done
        
        basefile=$filename"("$cnt")."$extension
        fi
    cp $file $backup_dir"/"$basefile
done

tar -zcf $zip_name".tar.gz" $backup_dir  &> /dev/null

echo "done"






