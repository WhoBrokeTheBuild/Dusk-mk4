

function get_distro()
{
    which dnf &>/dev/null && { echo fedora; return; }
    which yum &>/dev/null && { echo centos; return; }
    which zypper &>/dev/null && { echo opensuse; return; }
    which apt-get &>/dev/null && { echo ubuntu; return; }
}


distro=`get_distro`

case $distro in
    fedora)
        sudo dnf install -y \
            make \
            clang \
            valgrind \
            doxygen \
            SFML-devel \
            asio-devel \
            lua-devel \
            libX11-devel
        ;;
    centos)
        sudo yum install -y \
            make \
            clang \
            valgrind \
            doxygen \
            SFML-devel \
            asio-devel \
            lua-devel \
            libX11-devel
        ;;
    ubuntu)
        sudo apt-add-repository ppa:sonkun/sfml-stable
        sudo apt-get update
        sudo apt-get install -y \
            make \
            clang \
            valgrind \
            doxygen \
            libsfml \
            libsfml-dev \
            libasio-dev \
            liblua5.2-dev \
            libx11-dev
        ;;
    * )
        echo "Unsupported Distro"
        ;;
esac
