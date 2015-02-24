	#Extended color support
function EXT_COLOR () { echo -ne "\[\033[38;5;$1m\]"; }

# Base16 Shell
test=$(echo $-)
if [[ $test = *i* ]]; then
	BASE16_SHELL="$HOME/.config/base16-shell/base16-default.dark.sh"
	[[ -s $BASE16_SHELL ]] && source $BASE16_SHELL
fi

#Aliases
alias ls="ls --color"

#256 color!
export TERM="xterm-256color"

#utf-8
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
export LANGUAGE=en_US.UTF-8

cdl ()
{
	cd "$@" && ls
}


export PS1="`EXT_COLOR 21`\342\224\214\342\224\200`EXT_COLOR 21`\$([[ \$? != 0 ]] && echo \"[\[\033[0;31m\]\342\234\227\[\033[0;37m\]]\342\224\200\")`EXT_COLOR 21`[`EXT_COLOR 16`\u`EXT_COLOR 21`@`EXT_COLOR 12`\h`EXT_COLOR 21`]\342\224\200[`EXT_COLOR 13`\t`EXT_COLOR 21`]\342\224\200[`EXT_COLOR 02`\w`EXT_COLOR 21`]`EXT_COLOR 21`\n\[\033[0;37m\]\342\224\224\342\224\200\342\224\200\342\225\274\[\033[0m\] "
