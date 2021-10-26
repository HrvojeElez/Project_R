Dir_Path="/home/$USER"
current_dir=$PWD

delete_files()
{
    cd $Dir_Path
    find  -cmin -$1 -type f -printf "%p " -exec tar -cvzf backup.tgz "{}" +
    cd $current_dir
}

delete_files $1 
