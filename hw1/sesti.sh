Dir_Path="/home/$USER"
current_dir=$PWD

file_size_filter ()
{
    cd $Dir_Path
    find -size -$1c  -type f -printf "%p " -exec tar -cvzf backup.tgz "{}" +
    cd $current_dir
}

file_size_filter $1