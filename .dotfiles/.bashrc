#Extended color support
function EXT_COLOR () { echo -ne "\[\033[38;5;$1m\]"; }

#Prompt setup!
#PS1="\[\033[0;37m\]\342\224\214\342\224\200\$([[ \$? != 0 ]] && echo \"[\[\033[0;31m\]\342\234\227\[\033[0;37m\]]\342\224\200\")[$(if [[ ${EUID} == 0 ]]; then echo '\[\033[0;31m\]\h'; else echo '`EXT_COLOR 136`[\u]''`EXT_COLOR 255`[@]''`EXT_COLOR_23[\h]`'; fi)\[\033[0;37m\]]\342\224\200[\[\033[0;34m\]\t\[\033[0;37m\]]\342\224\200[\[\033[0;32m\]\w\[\033[0;37m\]]\n\[\033[0;37m\]\342\224\224\342\224\200\342\224\200\342\225\274 \[\033[0m\]"

export PS1="`EXT_COLOR 255`\342\224\214\342\224\200"\
"`EXT_COLOR 255`\$([[ \$? != 0 ]] && echo \"[\[\033[0;31m\]\342\234\227\[\033[0;37m\]]\342\224\200\")"\
"`EXT_COLOR 255`["\
"`EXT_COLOR 178`\u"\
"`EXT_COLOR 255`@"\
"`EXT_COLOR 51`\h"\
"`EXT_COLOR 255`]\342\224\200["\
"`EXT_COLOR 25`\t"\
"`EXT_COLOR 255`]\342\224\200["\
"`EXT_COLOR 34`\w"\
"`EXT_COLOR 255`]"\
"`EXT_COLOR 255`\n\[\033[0;37m\]\342\224\224\342\224\200\342\224\200\342\225\274\[\033[0m\] "

#Aliases
alias ls="ls --color"

#256 color!
export TERM="xterm-256color"

#utf-8
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
export LANGUAGE=en_US.UTF-8
