"====================================
" VIMRC of zj
" History, 20160228 add 
"====================================

"======== edit ===========
set number "设置行号
set cursorline 
set ruler 
set hlsearch
set incsearch "检索时，实时根据当前输入匹配到结果位置
set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)
set nocompatible
set history=1000
set backspace=indent,eol,start
set autoindent "自动将上一行的格式应用到下一行
set smartindent "智能的将上一行的对其格式应用到下一行
set tabstop=4
set shiftwidth=4
set showmatch
set showmode  "显示当前操作模式
filetype on

"--fold setting--
set foldmethod=syntax " 用语法高亮来定义折叠
set foldlevel=100 " 启动vim时不要自动折叠代码
set foldcolumn=5 " 设置折叠栏宽度



"========== color ============
set t_Co=256
colorscheme desert
syntax enable
syntax on

filetype plugin indent on

"========== ctags ============
set tags=tags
set tags+=~/.vim/systags


"========= cscope ============
if has("cscope")
	set csprg=/usr/local/bin/cscope
	set csto=1
	set cst
	set nocsverb
	" add any database in current directory
	if filereadable("cscope.out")
		cs add cscope.out
	endif
	set csverb
endif

nmap <C-@>s :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>g :cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
nmap <C-@>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
nmap <C-@>d :cs find d <C-R>=expand("<cword>")<CR><CR>



