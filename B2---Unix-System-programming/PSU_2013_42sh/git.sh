#!/bin/sh
## git.sh for  in /home/teyssa_r/rendu/CPE_2014_corewar
##
## Made by teyssa_r teyssa_r
## Login   <teyssa_r@epitech.net>
##
## Started on  Tue Aug 19 11:33:59 2014 teyssa_r teyssa_r
## Last update Fri Sep  5 00:02:21 2014 mar_b mar_b
##

function hcenter {
    text="$1"
    cols=`tput cols`
    IFS=$'\n'$'\r'
    for line in $(echo -e $text); do
	line_length=`echo $line| wc -c`
	half_of_line_length=`expr $line_length / 2`
	center=`expr \( $cols / 2 \) - $half_of_line_length`
	spaces=""
	for ((i=0; i < $center; i++)) {
	    spaces="$spaces "
	}
	echo "$spaces$line"
	done
}

function vcenter {
    text=$1
    rows=`tput lines`
    text_length=`echo -e $text | wc -l`
    half_of_text_length=`expr $text_length / 2`
    center=`expr \( $rows / 2 \) - $half_of_text_length`
    lines=""
    for ((i=0; i < $center; i++)) {
	lines="$lines\n"
    }
    echo -e "$lines$text$lines"
}

function center {
    text="$1"
    vcenter "$text"
}

function print_temp()
{
    answer=""
    while [ 1 ]; do
        while [ -z $answer ] ; do
            echo -e "Push or Pull ? (0 /1)"
            read answer
        done
        if [ $answer == "push" ]; then
	    make fclean
	    find -name "*~" -exec rm {} \; && echo -e "File(s) *~ delete"
	    find -name "#*" -exec rm {} \; && echo -e "File(s) #* delete"
	    hcenter "Directory Clean"
	    eval `ssh-agent` && ssh-add ~/.ssh/id_rsa_blih && echo -e "ssh ready"
	    git add --all
	    answer=""
	    while [ -z $answer ] ; do
		echo -e "Message for commit"
		read answer
            done
	    git commit -m $answer
	    git push -u origin master
            exit
        elif [ $answer == "pull" ]; then
            echo -e "Verifier bien d'avoir supprimez les fichier temporaire."
	    eval `ssh-agent` && ssh-add ~/.ssh/id_rsa_blih && echo -e "ssh ready"
	    git pull
	    exit
        fi
    done
}

clear
print_temp
