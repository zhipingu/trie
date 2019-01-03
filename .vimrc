set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')
" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

Plugin 'Valloric/YouCompleteMe'
Plugin 'scrooloose/syntastic'
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/zhi/YouCompleteMe'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup',{'rtp': 'vim/'}
Plugin 'vim-scripts/taglist.vim'
Plugin 'vim-scripts/The-NERD-Commenter'
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
set ai                          " 自动缩进，新行与前面的行保持—致的自动空格


set aw                        " 自动写，转入shell或使用：n编辑其他文件时，当前的缓冲区被写入

set nu        
set number                " 屏幕左边显示行号
set showmatch          " 显示括号配对，当键入“]”“)”时，高亮度显示匹配的括号
set showmode           " 处于文本输入方式时加亮按钮条中的模式指示器
set showcmd             " 在状态栏显示目前所执行的指令，未完成的指令片段亦会显示出来
set warn        " 对文本进行了新的修改后，离开shell时系统给出显示(缺省)
set ws               " 在搜索时如到达文件尾则绕回文件头继续搜索
set wrap       " 长行显示自动折行
colorscheme evening " 设定背景为夜间模式
filetype plugin on        " 自动识别文件类型，自动匹配对应的, “文件类型Plugin.vim”文件，使用缩进定义文件
"set autoindent            " 设置自动缩进：即每行的缩进值与上一行相等；使用 noautoindent 取消设置
set cindent                 " 以C/C++的模式缩进
set ignorecase       " 默认区分大小写
set ruler                     " 打开状态栏标尺
set scrolloff=5            " 设定光标离窗口上下边界 5 行时窗口自动滚动
set shiftwidth=4          " 设定 << 和 >> 命令移动时的宽度为 4
set softtabstop=4       " 使得按退格键时可以一次删掉 4 个空格,不足 4 个时删掉所有剩下的空格）
set tabstop=4           " 设定 tab 长度为 4
set expandtab
set wrap                     " 自动换行显示
syntax enable
syntax on                    " 自动语法高亮

set pastetoggle=<F9>
set guifont=Courier_new:h45:b:cDEFAULT
"set guifont=Courier\ new:h100:b:cDEFAULT

"YouCompleteMe
let g:ycm_global_ycm_extra_conf='~/.vim/bundle/YouCompleteMe/.ycm_extra_conf.py'

let g:syntastic_cpp_include_dirs='~/Chromium/src'
let g:syntastic_cpp_compiler = 'g++'  "change the compiler to g++ to support c++11
let g:syntastic_cpp_compiler_options = '-std=c++11 -stdlib=libc++' "set the options of g++ to suport c++11

set tags=~/work/adblock/tags
set tags=./tags

:nmap J j
:nmap K k
:map! jj <ESC> 
:cmap W w
:cmap Q q
:nmap H h
:nmap L l
:nmap I i
:map <c-]> g<c-]>
:vmap // \c<SPACE>
vmap H h
vmap J j
vmap K k
vmap L l
nnoremap ： :
cnoremap Q! q!
command Wq wq
command Q q
command WQ wq

set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
":inoremap { {<CR>}<Esc>O
":inoremap ( ()<Esc>i
":inoremap [ []<Esc>i
inoremap " ""<Esc>i
inoremap ' ''<Esc>i
inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap < <><Esc>i
inoremap { {<CR>}<Esc>O
autocmd Syntax html,vim inoremap < <lt>><Esc>i| inoremap > <c-r>=ClosePair('>')<CR>
inoremap ) <c-r>=ClosePair(')')<CR>
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap > <c-r>=ClosePair('>')<CR>
inoremap } <c-r>=CloseBracket()<CR>
inoremap " <c-r>=QuoteDelim('"')<CR>
inoremap ' <c-r>=QuoteDelim("'")<CR>


function ClosePair(char)
 if getline('.')[col('.') - 1] == a:char
 return "\<Right>"
 else
 return a:char
 endif
endf

function CloseBracket()
 if match(getline(line('.') + 1), '\s*}') < 0
 return "\<CR>}"
 else
 return "\<Esc>j0f}a"
 endif
endf

function QuoteDelim(char)
 let line = getline('.')
 let col = col('.')
 if line[col - 2] == "\\"
 return a:char
 elseif line[col - 1] == a:char
 return "\<Right>"
 else
 return a:char.a:char."\<Esc>i"
 endif
endf

"设置= + - * 前后自动空格
"设置，后面自动添加空格
"if exists("g:equ")
":inoremap = <c-r>=EqualSign('=')<CR>
":inoremap + <c-r>=EqualSign('+')<CR>
"":inoremap - <c-r>=EqualSign('-')<CR>
"":inoremap * <c-r>=EqualSign('*')<CR>
"":inoremap / <c-r>=EqualSign('/')<CR>
"":inoremap > <c-r>=EqualSign('>')<CR>
"":inoremap < <c-r>=EqualSign('<')<CR>
:inoremap == <c-r>=EqualSign("==")<CR>
:inoremap ? <c-r>=EqualSign('?')<CR>
"":inoremap : <c-r>=EqualSign(':')<CR>
:inoremap += <c-r>=EqualSign("+=")<CR>
:inoremap -= <c-r>=EqualSign('-=')<CR>
:inoremap *= <c-r>=EqualSign('*=')<CR>
:inoremap /= <c-r>=EqualSign('/=')<CR>
:inoremap >= <c-r>=EqualSign('>=')<CR>
:inoremap <= <c-r>=EqualSign('<=')<CR>

:inoremap && <c-r>=EqualSign("&&")<CR>
:inoremap <Bar><Bar> <c-r>=EqualSign("<Bar><Bar>")<CR>
"":inoremap \|\\|\ <c-r>=EqualSign("||"")<CR>
"":inoremap % <c-r>=EqualSign('%')<CR>
:inoremap , ,<space>
""endif


function! EqualSign(char)
if a:char  =~ '='  && getline('.') =~ ".*("
return a:char
endif 
let ex1 = getline('.')[col('.') - 3]
let ex2 = getline('.')[col('.') - 2]


if ex1 =~ "[-=+<>\/\*?:%&|]"
if ex2 !~ "\s"
return "\<ESC>i".a:char."\<SPACE>"
else
return "\<ESC>xa".a:char."\<SPACE>"
endif 
else
if ex2 !~ "\s"
return "\<SPACE>".a:char."\<SPACE>\<ESC>a"
else
return a:char."\<SPACE>\<ESC>a"
endif 
endif
endf
