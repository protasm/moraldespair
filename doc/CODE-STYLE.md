# CODE-STYLE.md

## Purpose

This document defines the **authoritative coding style and conventions** for the *Moral Despair* mudlib.

All human contributors and automated agents (including Codex) **must follow this document** when writing or modifying code. Consistency, clarity, and restraint are valued over cleverness or density.

If existing code conflicts with this style, **new or modified code must still follow this document** unless explicitly instructed otherwise.

---

## Guiding Principles

1. **Clarity over brevity**
2. **Explicit is better than implicit**
3. **Boring code is good code**
4. **Assume future readers are tired**

This mudlib is meant to evolve slowly and deliberately. Code should be easy to read, easy to debug, and easy to reason about months or years later.

---

## Indentation and Whitespace

- Use **two (2) spaces** for indentation
- Do **not** use tabs
- Indent all block contents, including `if`, `else`, `while`, `for`, and function bodies
- Leave a blank line between logical sections of code

---

## Braces

- Use **K&R style braces**
- Opening brace goes on the **same line** as the statement
- Closing brace is on its own line

Correct:

```
if (condition) {
  do_something();

  bar = "bar";
} else {
  do_something_else();

  show_success();
}
```

---

## Variable Declarations

### General Rules

- Declare variables **at the top of the scope** in which they are used
- Do not interleave declarations and executable statements
- Prefer multiple simple declarations over clever combined ones

### File-Scope Declarations

```
int x, y, z;
string foo;
object obj;
```

### Function-Scope Declarations

```
void init() {
  int blah;
  boolean status;

  ::init();
  ...
}
```

---

## Assignment and Initialization

- Assign values **after declarations**, not inline
- One logical assignment per line

Correct:

```
blah = 99;
status = false;
```

Avoid:

```
int blah = 99;
boolean status = false;
```

---

## Function Definitions

- Function return types must be explicit
- Function names should be **lowercase with underscores**
- Keep functions short and single-purpose

Example:

```
int do_something(boolean foo) {
  int a, b, c;

  write("foo is: " + foo + "\n");

  if (foo)
    a = 9;
  else {
    a = 11;

    do_something();
  }

  b = 4;
  c = 0;

  return a + b - c;
}
```

---

## Control Flow

- Always use braces for multi-line blocks
- Never use braces for single-line blocks
- Prefer clear `if / else` chains over clever ternaries

Correct:

```
if (foo)
  a = 9;
else {
  a = 11;
  b = 9;
}
```

Avoid:

```
a = foo ? 9 : 11;
```

---

## Return Statements

- Use `return;` explicitly in `void` functions
- Use a single return point unless clarity strongly benefits otherwise
- Unless contained in a control flow structure, separate return statements from 
  preceeding lines with a blank line.

```
if (foo)
  a = 9;

return;
```

---

## Method Overrides

- When overriding inherited methods, call the parent explicitly and early

```
::init();
```

---

## Comments

- Comments should explain **why**, not **what**
- Avoid redundant comments
- Use comments sparingly and deliberately

---

## Line Length

- Where text is presented to the player, insert gramatically correct line breaks wherever necessary to ensure that each line of text is as close as possible to 80 characters without going over.

---

## Discouraged Patterns

Agents and contributors should avoid:

- Inline initialization in declarations
- Dense one-liners
- Clever macro tricks
- Deep inheritance chains without strong justification
- Premature abstractions

---

## Style Authority

This file is **authoritative**.

If a conflict arises between:
- Existing code
- Personal preference
- External mudlib conventions

**CODE-STYLE.md wins.**

When in doubt, choose the most explicit and least surprising option.

