
"====================================
" VIMRC of zj
" History, 20160228 add 
"====================================

set number
set cursorline
set ruler
set hlsearch
set incsearch
set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)
set nocompatible
set history=1000

syntax on

"colorscheme molokai




"---------- program --------------------
func! CompileGcc()
    exec "w"
    let compilecmd="!gcc -Wall"
    let compileflag="-o %< "
    exec compilecmd." % ".compileflag
endfunc
func! CompileGpp()
    exec "w"
    let compilecmd="!g++ -Wall"
    let compileflag="-o %< "
    exec compilecmd." % ".compileflag
endfunc

func! RunPython()
        exec "!python %"
endfunc
func! CompileJava()
    exec "!javac %"
endfunc


func! CompileCode()
        exec "w"
        if &filetype == "cpp"
                exec "call CompileGpp()"
        elseif &filetype == "c"
                exec "call CompileGcc()"
        elseif &filetype == "python"
                exec "call RunPython()"
        elseif &filetype == "java"
                exec "call CompileJava()"
        endif
endfunc

func! RunResult()
        exec "w"
        if &filetype == "cpp"
            exec "! ./%<"
        elseif &filetype == "c"
            exec "! ./%<"
        elseif &filetype == "python"
            exec "call RunPython"
        elseif &filetype == "java"
            exec "!java %<"
        endif
endfunc

map <F5> :call CompileCode()<CR>
imap <F5> <ESC>:call CompileCode()<CR>
vmap <F5> <ESC>:call CompileCode()<CR>

map <F6> :call RunResult()<CR>



