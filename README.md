# Mini PHP Lexer

A lexer/scanner for mini PHP, described below.

## Implementation

- Implemented using Soft-Coded method via a transition table-based approach
- Uses double buffering
  - Each can store upto 4096 characters
  - 4096 was chosen to sync with a typical IO call's buffer
- Total lexeme length is limited to 4096 characters

## Language Features:

The mini PHP language includes basic constructs such as variables, arithmetic operations, conditional statements `if`, loops `while`, and multiline comments.

## Lexical Units:

<b>Keywords</b>: `if`, `while`. <br>
<b>Identifiers</b>: Alphanumeric strings starting with a `$`. <br>
<b>Literals</b>: Integer numbers, string literal enclosed in single quote. <br>
<b>Operators</b>: Assignment operator `=`, comparison operators `==`, `!=` <br>
<b>punctuations</b>: `;` `(` `)` `{` `}` <br>
<b>Comments</b>: Multiline comments enclosed between `/*` and `*/` <br>

## DFA

<img src="./DFA/DFA - Mini PHP Lexer.png" />
