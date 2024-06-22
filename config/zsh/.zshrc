# User configuration sourced by interactive shells

# Change the prompt
PROMPT="%B%F{red}[%B%F{blue}$HOST %F{yellow}%~%B%F{red}]%f%b$ "

# Load profile and aliases if existent.
[ -f "$ZDOTDIR/profile" ] && source "$ZDOTDIR/profile" && [ -f "$ZDOTDIR/aliasrc" ] && source "$ZDOTDIR/aliasrc"

# History
HISTFILE=$ZDOTDIR/history
HISTSIZE=SAVEHIST=1000000
setopt extendedhistory
setopt INC_APPEND_HISTORY

# Prompt for spelling correction of commands.
setopt CORRECT

# Customize spelling correction prompt.
SPROMPT='zsh: correct %F{red}%R%f to %F{green}%r%f [Y/n]? '

# Disable ctrl-s to freeze terminal.
stty stop undef

# keybinds
insert_sudo () { zle beginning-of-line; zle -U "sudo " }
zle -N insert-sudo insert_sudo
bindkey "^k" insert-sudo

# Use lf to switch directories and bind it to ctrl-o
lfcd () {
    tmp="$(mktemp)"
    lf -last-dir-path="$tmp" "$@"
    if [ -f "$tmp" ]; then
        dir="$(cat "$tmp")"
        rm -f "$tmp" >/dev/null
        [ -d "$dir" ] && [ "$dir" != "$(pwd)" ] && cd "$dir"
    fi
}
bindkey -s '^o' 'lfcd\n'

bindkey -s '^a' 'bc -lq\n' # calculator
bindkey -s '^f' 'cd "$(dirname "$(fzf)")"\n' # dir chooser

# Better completion for killall
zstyle ':completion:*:killall:*' command 'ps -u $USER -o cmd'

# Tab completion from both ends
setopt completeinword

# Edit line in vim with ctrl-e:
autoload edit-command-line; zle -N edit-command-line
bindkey '^e' edit-command-line

# vi mode
bindkey -v
export KEYTIMEOUT=1

# Reverse search
bindkey '^r' history-incremental-search-backward

# Stopwatch and countdown commands
countdown() {
    start="$(( $(date '+%s') + $1))"
    while [ $start -ge $(date +%s) ]; do
        time="$(( $start - $(date +%s) ))"
        printf '%s\r' "$(date -u -d "@$time" +%H:%M:%S)"
        sleep 0.1
    done
}

stopwatch() {
    start=$(date +%s)
    while true; do
        time="$(( $(date +%s) - $start))"
        printf '%s\r' "$(date -u -d "@$time" +%H:%M:%S)"
        sleep 0.1
    done
}

# Change cursor shape for different vi modes.
function zle-keymap-select () {
    case $KEYMAP in
        vicmd) echo -ne '\e[1 q';;      # block
        viins|main) echo -ne '\e[5 q';; # beam
    esac
}
zle -N zle-keymap-select
zle-line-init() {
    zle -K viins # initiate `vi insert` as keymap (can be removed if `bindkey -V` has been set elsewhere)
    echo -ne "\e[5 q"
}
zle -N zle-line-init
echo -ne '\e[5 q' # Use beam shape cursor on startup.
preexec() { echo -ne '\e[5 q' ;} # Use beam shape cursor for each new prompt.

# INITIALIZE ZSH PLUGINS
source ${ZDOTDIR}/plugins/init-plugins.zsh
