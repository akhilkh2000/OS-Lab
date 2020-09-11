#!/bin/sh
#
for item in `ls`
     do
       if [ ! -f $item ]; # the ! -f $item is file 
                          # checker which checks 
                          #if file is a plain file 
       then 
          continue #(rejects al directories)

          fi #end of if-else 

        new=`echo $item  | tr '[A-Z]' '[a-z]'` #new filename renamed 
                                              #using output of echo to tr
                                              # which changes uppercase to 
                                              #lowercase based on flags
        if [ $new != $item ]; then  #if name has been changed
          mv -i $item $new #rename and  -i to ask permission if overwrite 
        fi #end of if-else 
        done