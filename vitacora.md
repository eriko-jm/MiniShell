- error with readline: not istaled

```
# include <readline/readline.h>
# include <readline/history.h>
```

- solution: sudo apt install libreadline-dev
- check after instalation: find /usr/include -name readline.h

---

- get current terminal settings: tcgetattr(STDIN_FILENO, &termios);
  - does we need this?
    - if you want to desable the echo as chars things like Ctrl+c --> ^c
		- then we need to get the attributes, change them and set them again with tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
  - [tcsetattr(3)](https://linux.die.net/man/3/tcsetattr)
  - [tcsetattr - set the parameters associated with the terminal](https://pubs.opengroup.org/onlinepubs/009696799/functions/tcsetattr.html)
    - If optional_actions is TCSANOW, the change shall occur immediately.

---
# Lexer
[What is a Lexer, Anyway?](https://dev.to/cad97/what-is-a-lexer-anyway-4kdo)
 - Lexical tokenization is conversion of a text into (semantically or syntactically) meaningful lexical tokens belonging to categories defined by a lexer program.


---

# Grammar

[Formal language](https://en.wikipedia.org/wiki/Formal_language)
 - Given a non-empty set Σ, a formal language L over Σ is a subset of Σ∗, where Σ∗ is the set of all possible finite-length words over Σ. We call the set Σ *the alphabet* of L. On the other hand, given a formal language L over Σ, a word w ∈ Σ∗ is well-formed if w ∈ L. Similarly, an expression 
E ⊆ Σ∗ is well-formed if E ⊆ L. Sometimes, a formal language L over Σ has a set of clear rules and constraints for the creation of all possible well-formed words from Σ∗.
  - A formal language is a set of strings whose symbols are taken from a set called "alphabet".
  - in short: a (possibly infinite) set of finite-length strings composed from a given alphabet.

[Formal grammar](https://en.wikipedia.org/wiki/Formal_grammar)
- A formal grammar is a set of symbols and the production rules for rewriting some of them into every possible string of a formal language over an alphabet. A grammar does not describe the meaning of the strings—only their form.
- A grammar G consists of the following components:
  - A finite set N of nonterminal symbols, that is disjoint with the strings formed from G.
  - A finite set Σ of terminal symbols that is disjoint from N.
  - A finite set P of *production rules*, each rule of the form (Σ ∪ N)*N(Σ ∪ N)* → (Σ ∪ N)* where ∗ is the Kleene star operator [a kind of unary operator] and ∪ denotes set union.
  - A distinguished symbol S ∈ N that is the start symbol, also called the sentence symbol.
 - A grammar is formally defined as the tuple (N,Σ,P,S)
 - The Chomsky hierarchy: When Noam Chomsky first formalized generative grammars in 1956,[2] he classified them into types now known as the Chomsky hierarchy. The difference between these types is that they have increasingly strict production rules and can therefore express fewer formal languages
   - Two important types are context-free grammars (Type 2) and regular grammars (Type 3). The languages that can be described with such a grammar are called context-free languages and regular languages, respectively.

A formal grammar is essentially a set of production rules that describe all possible strings in a given formal language. Production rules are simple replacements.

[Grammar Production Rules and Different Types](https://youtu.be/8Th7KB0uEqs?si=6ktnv0hjUWlBON8f)
 - **Type 2: (context-free grammars)**
   - α ⟶ β: |α| = 1, ∃ v ∈ α (que solo puede haber un α por regla de produccion y tiene que ser noterminal)
 - Type 3: (regular grammars)
   - α ⟶ β: |α| = 1 & β ≤ 2, (pero con |β| > 0: 1 terminal o 1 terminal y 1 noterminal)

[Grammar in Theory of Computation](https://www.geeksforgeeks.org/theory-of-computation/introduction-to-grammar-in-theory-of-computation/)
 - P = { A -> Aa, A -> Ab, A -> a ,A -> b, A -> 𝜺}    #Set of all production rules

[Introduction To Parsers](https://youtu.be/-BjWCx-50Lc?si=ky_Hyrd81DlstAlT)
 - Terminals: items that match 1 to 1 with tokens in the grammar specification
 - NonTerminal: Those items that do NOT match 1 to 1 with our token spicification
    - can be built by combination of Terminals and others NonTerminal
 - It has to define a set of rules
	- [Chomsky normal form](https://en.wikipedia.org/wiki/Chomsky_normal_form)

[Abstract syntax tree (AST)](https://en.wikipedia.org/wiki/Abstract_syntax_tree)
 - representation of the abstract syntactic structure of text (often source code) written in a formal language.

<ins>more sources</ins>:
  - [Grammars and Parsing Tutorial](https://youtu.be/PooQrbFrd_U?si=puiz9XIPO4PGibET)
	- A *language*: any system of formalized symbols, signs, etc. used for comunication.
	- A *gramar*: set of **strunctural rules** that governs sentences, words, etc. in a natural language.
	- Top-down vs Bottom-up Parsing: (returns true or false depending on the sentence can be parsed or not)
		- Top-down: starts witha a *"start-symbol"* and decontructs it using left-side derivarion. Easy to make and for humans. (starts with the symbols of the lenguage and try to get the original sentence)
		- Bottom-up: starts trying to match symbols with valid representation in the lenguage, uses right-side derivarion. Works better depending on the lenguage. (starts with the original sentence and works up, trying to get a correct symbol representatio). 
	- CAREFUL with invalid languages. There are rules to gide how to make a valid grammar. Poorly written grammars can result in serious computer errors.
  - [Formal Languages](https://www.csfieldguide.org.nz/en/chapters/formal-languages/)

---

# Parsing
Pratt Parsing:

- **[Parsing explained: grammars, trees, and everything in between](https://youtu.be/HuSCzN5IPAo?si=tU9xgHH-XDn8acWY)**
  - Lexical Analysis ⟶ Syntactic Analysis ⟶ Semantic Analysis
- [Pratt Parsing by Core Dumped](https://youtu.be/0c8b7YfsBKs?si=9vq3iBSC53R27VpD)
- [Simple but Powerful Pratt Parsing](https://matklad.github.io/2020/04/13/simple-but-powerful-pratt-parsing.html)

---

Flujo de entrada:
readline() -> Lexer (Tokenizer) -> (lista de tokens) -> parser -> AST (o lista de comandos) -> Expander ->  (lista de comandos expandida) -> send final structure to executor
entrada -> list(tokens) -> expand(cmd) -> list(cmd) 

Se lee lalinea.
Lexer: recibe el string del read line y devuelve una lista de tokens (la procesa y le da significado a las unidades)
	--> read the string skiping white spaces (skip when isspace)untill I find EOL. If I found something different than white space I'll ask: is this operator? If it is I'll check witch one and place TOKEN acordingly. If it is not an operator I'll try to find a delimiter (an operator, space or EOL) fodward, and disign as WORD everything in between

Parser: recibe una lista de tokens y la convierte en una lista de ejecucion (procesa la lista de tokens y la convierte en una esctructura con significado)cmd_list

hacer toda la secuencia primero e iterativamente ir mejorando la funcionalidad:

readline()	-hecho
Lexer()		- copia linea en nodo (next: split line; identify some tokens)

---
# Tests

- Given an input string, should returnt a list of CMDs based on that:

1. Basic

```
ls
pwd
echo hello
echo hello world
cd ../
cd /home
export
unset
env
exit
```
spaces:
```
         ls
ls          
    ls     
echo     hello
  echo     hello    world     
	echo		hello	world			
```
args:
```
ls -l
ls -al
grep hola file1
cat file1 file2 file3
echo hola mundo !!!
```

2. Pipes

```
ls | wc
ls | grep minishell | wc
a | b | c | d | e | f | g | h
cat file1 | grep hola | sort | uniq
```
spaces:
```
ls|wc
ls |wc
ls| wc
ls    |    wc
```

3. Redirections

```
echo hola > file1
cat < file1
echo hola >> file1
cat < infile > outfile
grep hola < infile > outfile
grep hola >> output
echo hola > file1 > file2
cat < file1 | grep hola
cat file1 | grep hola > outfile
cat << EOF
cat << EOF > outfile
cat < infile | grep hola | wc > outfile
```

Error:
```
$ cat <<
bash: syntax error near unexpected token `newline'
```

4. Quotes

```
echo 'hola'
echo 'hola mundo'
echo "hola"

echo "hola mundo"
echo "hola" mundo

echo hola "mundo"
echo 'hola' "mundo"

echo hola"mundo"
echo "hola"'mundo'
echo 'hola'"mundo"

echo ""
echo ''
echo "" hola
echo '' hola

echo $HOME
echo "$HOME"
echo '$HOME'

echo hola$USER
echo "$USER$HOME"
```

5. Here-doc
```
cat << EOF
cat <<EOF
cat << EOF | wc
cat <<EOF > out
cat << EOF1 << EOF2
```

6. More
```
cat < input.txt | grep "hello world" | sort | uniq -c > out.txt
echo "hola mundo" >> file
grep 'abc def' < in | cat | wc > out
echo a"b"c'd'e
abcde
echo """"hola""""
echo ''""''
cat<<EOF|grep hola>>out
echo""""hola
echo''hola
echo""
echo''
echo""""
echo a""""b
echo "a"'b'"c"
echo 'a'"b"'c'
```

error (invalid)
```
|
ls |
>
cat <
cat > |
| ls
ls |
ls || wc
cat >
cat <
cat >>
cat <<
cat > > file
cat < |
echo "
echo '
echo "hola
echo 'hola


```