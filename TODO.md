Parser:
remove debug
complete Event parser

Core:
remove Event ptr from private: -> make Event ptr in exec() and pass to core_.proccess();
add base logic
add base implementations

TmExtension:
~rename
add constructor/method from string;
add check if string is correct, put_time is not suitable;

ErrorHandler:
split defenition of error::raise into .cpp if possible

.global:
rename unified header for usefull includes
prettify TODO.md

Makefile:
rewrite to correct modular system

## esimated completion ~70%
## ~ - probably
## ? - not resolved