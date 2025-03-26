#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 2000 ]; then
    echo "[ Error |@UnixeID(Yeye)]"
    exit 1
fi
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -S bigtext -t '♨️ Restriction' 'Tag' "$sor" > /dev/null 2>&1
}
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. Restriction.... "
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Point                    :  2.0 [ Oulet ]"
    echo "       - Release               :  26 - Mar - 2025"
    echo "       - Name Shell         :  Restriction"
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority Restriction Optimization. "
    sleep 2
    echo
    echo
     rm -rf /data/local/tmp/*
     cp /sdcard/strip/std /data/local/tmp 
     chmod +x /data/local/tmp/std
       if [ "$1" = "-O" ]; then
        shell "Wait To Apply Restriction system Optimization Min 1-3"
        /data/local/tmp/std -O
    elif [ "$1" = "-C" ]; then
         shell "Wait To Apply Claer and Redus resoult Min 1-3"
        /data/local/tmp/std -C
    elif [ "$1" = "-R" ]; then
         shell "Wait To Reset kode Restriction To default Min 1-3"
        /data/local/tmp/std -R
    elif [ "$1" = "-h" ]; then
       /data/local/tmp/std -h
    elif [ "$1" = "--help" ]; then
       /data/local/tmp/std --help
    else
        printf "Faild To Program Opsi Restriction....!\n"
    fi
    