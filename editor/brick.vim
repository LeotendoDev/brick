
if exists("b:current_syntax")
  finish
endif

set iskeyword=a-z,A-Z,-,*,_,!,@
syntax keyword brickTodos TODO XXX FIXME NOTE

" Language keywords
syntax keyword brickKeywords if else elif func end return use lambda here space class   

" Comments
syntax region brickCommentLine start="//" end="$"   contains=brickTodos

" String literals
syntax region brickString start=/\v"/ skip=/\v\\./ end=/\v"/ contains=brickEscapes

" Char literals
syntax region brickChar start=/\v'/ skip=/\v\\./ end=/\v'/ contains=brickEscapes

" Escape literals \n, \r, ....
syntax match brickEscapes display contained "\\[nr\"']"

" Number literals
syntax region brickNumber start=/\s\d/ skip=/\d/ end=/\s/

" Type names the compiler recognizes
syntax keyword brickTypeNames uint bool ref string

" Set highlights
highlight default link brickTodos Todo
highlight default link brickKeywords Keyword
highlight default link brickCommentLine Comment
highlight default link brickString String
highlight default link brickNumber Number
highlight default link brickTypeNames Type
highlight default link brickChar Character
highlight default link brickEscapes SpecialChar

let b:current_syntax = "brick"

