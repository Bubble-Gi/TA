%option c++
%option noyywrap
SPTAB [ \\t]+
WORD [a-zA-Z][A-Za-z0-9._]*
%%
<INITIAL>{
^(?-i:create) {return 1;}
(?-i:as) {return 5;}
(?-i:join) {return 6;}
{WORD} {return 2;}
"(" {return 3;}
")" {return 4;}
"," {return 7;}
{SPTAB} {return 8;}
\n {return 0;}
.;
}
%%
